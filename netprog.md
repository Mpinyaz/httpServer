# Network programming in C

1. **TCP (Transmission Control Protocol)**: TCP is responsible for ensuring the reliable transmission of data across a network. It breaks down the data into packets and reassembles them at the destination. TCP also manages the control of data flow, ensuring that packets are not lost, duplicated, or delivered out of order. It establishes a connection between the sender and receiver before data transmission and maintains it until all data is transferred successfully.
2. **IP (Internet Protocol)**: IP handles the addressing and routing part of the process. It ensures that packets are sent from the source to the correct destination. Each device in a network has a unique IP address that identifies it. IP routes the data packets based on these addresses.

A socket is essentially an endpoint for sending and receiving data. Socket programming is a way to connect two nodes on a network to communicate with each other. To understand socket programming, it’s crucial to be familiar with the concept of a client and a server. The server is a program that runs on a specific computer on the network and waits for requests from clients. The client is a program that initiates communication with the server.

When a client wants to communicate with a server, it must know the server’s address and port number. Similarly, the server must be set up to listen for incoming connections on a specific port number. This is where socket programming comes into play.
