#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 4567
#define BUFFER_SIZE 1024

int main() {
    int socketfd;
    struct sockaddr_in server_addr;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    char msg[BUFFER_SIZE];
    while (1) {
        printf("Enter message (or 'exit' to quit): ");
        fgets(msg, sizeof(msg), stdin);
        if (strcmp(msg, "exit\n") == 0) {
            break;
        }
        send(socketfd, msg, strlen(msg), 0);
    }

    close(socketfd);
    printf("Connection closed.\n");
    return 0;
}