#ifndef SERVER_H
#define SERVER_H
#include <openssl/ssl.h>
#define PORT 8080
#define BACKLOG 5
#define MAXIMUM_REQUEST_SIZE 2048
#define ROOT "./src"
#define SERVER_CERT "cert.pem"
#define SERVER_KEY "key.pem"
#define CA_CERT "ca.pem"

SSL_CTX *create_context(const char *ca_pem, const char *cert_pem,
                        const char *key_pem);
void server_handler(SSL *ssl);
#endif
