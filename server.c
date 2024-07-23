#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 5
#define MAXIMUM_REQUEST_SIZE 2048
#define ROOT "./src"
#define SERVER_CERT "cert.pem"
#define SERVER_KEY "key.pem"

void handling(SSL *ssl) {
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

int main(void) {
  int server_fd, client_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  SSL_CTX *ctx;
  SSL *ssl;
  // Initialize OpenSSL
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();

  // Create SSL context
  const SSL_METHOD *method = SSLv23_server_method();
  ctx = SSL_CTX_new(method);
  if (!ctx) {
    perror("Unable to create SSL context");
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  // Configure SSL context
  if (SSL_CTX_use_certificate_file(ctx, SERVER_CERT, SSL_FILETYPE_PEM) <= 0) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  if (SSL_CTX_use_PrivateKey_file(ctx, SERVER_KEY, SSL_FILETYPE_PEM) <= 0) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }
  // Create a socket
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
  address.sin_port = htons(PORT);

  // Bind the socket to the address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for connections
  if (listen(server_fd, BACKLOG) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  printf("Connection listening on PORT: %d\n", PORT);

  while (1) {
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address,
                                (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client_socket);

    if (SSL_accept(ssl) <= 0) {
    } else {
      // Handle the client message
      handling(ssl);
    };
    close(client_socket);
  }

  close(server_fd);
  SSL_CTX_free(ctx);
  EVP_cleanup();
  return 0;
}
