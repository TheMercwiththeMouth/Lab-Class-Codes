#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
void bubble_sort(int[], int);
int main(int argc, char* argv[]){
    int socket_desc, client_socket, c, read_size;
    struct sockaddr_in server, client;
    int i, n;
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc==-1){
        printf("The socket could not be created.");
        exit(EXIT_FAILURE);
    }
    puts("Socket Created");
    server.sin_family= AF_INET;
    server.sin_addr.s_addr= INADDR_ANY;
    server.sin_port = htons(8356);

    if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server))<0){
        perror("Bind Failed. ERROR");
        exit(EXIT_FAILURE);
    }
    puts("Binding Done");

    listen(socket_desc, 3);
    puts("Waiting for incoming connections...");
    c=sizeof(struct sockaddr_in);

    client_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);

    if(client_socket<0){
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    puts("Connection Accepted");
    int message[10000];
    for(int i=0; i<10000; i++){
        message[i]= 10000;
    }
    while((read_size = recv(client_socket, &message, sizeof(message), 0))>0){
        bubble_sort(message, sizeof(message)/sizeof(int));
        write(client_socket, &message, sizeof(message));
    }

    if(read_size == 0){
        puts("Client disconnected");
    }2
    else if(read_size==-1){
        puts("recv failed");
    }
    //close(socket_desc);
    return 0;
}
void bubble_sort(int list[], int n)
{
    int c, d, t;
 
    for (c = 0; c < (n - 1); c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d + 1]) {
 
                /* Swapping */
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}