# Makefile for SSL HTTP Server

CC = gcc
CFLAGS = -I/usr/local/opt/openssl/include
LDFLAGS = -L/usr/local/opt/openssl/lib -lssl -lcrypto
TARGET = server
SRCS = server.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)
