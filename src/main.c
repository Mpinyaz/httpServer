#include "../include/errorhandling.h"
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#define SERVER_PORT 80
#define MAXLINE 4096

int main(int argc, char **argv) {

  int server_fd, client_socket;
  struct sockaddr_in address;

  if (argc != 2) {
    err_n_die("Usage: %s <port>", argv[0]);
    return -1;
  }

  int portnum = atoi(argv[1]);
  if (portnum < 1 || portnum > 65535) {
    err_n_die("Invalid port number");
    return -1;
  }
}
