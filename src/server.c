#include "server.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
SSL_CTX *create_context(const char *ca_pem, const char *cert_pem,
                        const char *key_pem) {
  const SSL_METHOD *method;
  SSL_CTX *ctx;
  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();

  BIO *certbio = BIO_new(BIO_s_file());
  BIO *outbio = BIO_new_fp(stdout, BIO_NOCLOSE);

  if (SSL_library_init() < 0) {
    BIO_printf(outbio, "Could not initialize the OpenSSL library !\n");
  }

  method = SSLv23_server_method();
  ctx = SSL_CTX_new(method);
  if (!ctx) {
    perror("Unable to create SSL context");
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }
  if (SSL_CTX_load_verify_locations(ctx, ca_pem, NULL) != 1) {
    fprintf(stderr, "Error loading CA file and/or directory\n");
    goto fail;
  }

  SSL_CTX_set_client_CA_list(ctx, SSL_load_client_CA_file(ca_pem));
  if (SSL_CTX_use_PrivateKey_file(ctx, key_pem, SSL_FILETYPE_PEM) != 1) {
    fprintf(stderr, "Error loading private key file\n");
    goto fail;
  }

  if (SSL_CTX_check_private_key(ctx) != 1) {
    fprintf(stderr, "Error checking private key\n");
    goto fail;
  }

  SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);
  SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
                     NULL);
  SSL_CTX_set_verify_depth(ctx, 1);

  return ctx;
fail:
  SSL_CTX_free(ctx);
  return NULL;
}

void server_handler(SSL *ssl) {
  char request[MAXIMUM_REQUEST_SIZE] = {0};
  SSL_read(ssl, request, MAXIMUM_REQUEST_SIZE);

  char method[10], path[255], protocol[20];

  sscanf(request, "%s %s %s", method, path, protocol);

  char filePath[265];
  sprintf(filePath, "%s%s", ROOT, path);

  if (strcmp(path, "/") == 0) {
    sprintf(filePath, "%s/index.html", ROOT);
  }

  if (strcmp(method, "GET") == 0) {
    int file = open(filePath, O_RDONLY);
    if (file == -1) {
      char response[1024] = "HTTP/1.1 404 Not Found\r\nContent-Type: "
                            "text/html\r\n\r\n<h1>404 Not Found!</h1>";
      SSL_write(ssl, response, strlen(response));
    } else {
      char response_header[512];
      sprintf(response_header,
              "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

      // Send the headers first
      SSL_write(ssl, response_header, strlen(response_header));

      char buf[1024];
      ssize_t readBytes;

      // Send the file content
      while ((readBytes = read(file, buf, sizeof(buf))) > 0) {
        SSL_write(ssl, buf, readBytes);
      }
      close(file);
    }
  }
  SSL_shutdown(ssl);
  SSL_free(ssl);
}

void showCerts(SSL *ssl) {
  X509 *cert;
  char *line;

  cert = SSL_get_peer_certificate(ssl);
  if (cert != NULL) {
    printf("Server certificates:\n");
    line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
    printf("Subject: %s\n", line);
    free(line);
    line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
    printf("Issuer: %s\n", line);
    free(line);
    X509_free(cert);
  } else
    printf("No certificates.\n");
}

int openListener(int port) {
  int server_fd;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Define the server address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  // Bind the socket to the address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for connections
  if (listen(server_fd, SOMAXCONN) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  printf("Connection listening on PORT: %d\n", port);
  return server_fd;
}
