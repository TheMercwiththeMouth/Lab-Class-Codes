#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4567
#define MAX_CLIENTS 20
#define BUFFER_SIZE 1024

int num_clients = 0;
int client_sockets[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *manage_clients(void *arg) {
    int socketfd_client = *((int *)arg);
    char buf[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(socketfd_client, buf, sizeof(buf), 0);
        if (bytes_received <= 0) {
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < num_clients; i++) {
                if (client_sockets[i] == socketfd_client) {
                    num_clients--;
                    for (int j = i; j < num_clients; j++) {
                        client_sockets[j] = client_sockets[j + 1];
                    }
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            close(socketfd_client);
            pthread_exit(NULL);
        }

        buf[bytes_received] = '\0';
        printf("Received: %s", buf);

        // pthread_mutex_lock(&mutex);
        // for (int i = 0; i < num_clients; i++) {
        //     if (client_sockets[i] != socketfd_client) {
        //         send(client_sockets[i], buf, bytes_received, 0);
        //     }
        // }
        // pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int socketfd_server;
    struct sockaddr_in server_addr;

    socketfd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd_server == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(socketfd_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(socketfd_server, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if (num_clients < MAX_CLIENTS) {
            int socketfd_client = accept(socketfd_server, NULL, NULL);
            if (socketfd_client == -1) {
                perror("Accepting connection failed");
                continue;
            }

            pthread_mutex_lock(&mutex);
            client_sockets[num_clients] = socketfd_client;
            num_clients++;
            pthread_mutex_unlock(&mutex);

            pthread_create(&threads[num_clients - 1], NULL, manage_clients, &socketfd_client);
        }
    }

    close(socketfd_server);
    return 0;
}