#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int palindromeCheck(char[], int);
int main(int argc, char* argv[]){
    int socket_desc, client_socket, c, read_size;
    struct sockaddr_in server, client;
    int i, flag;
    
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
    char message[100];
    // while((read_size = recv(client_socket, &message, sizeof(message), 0))>0){
    //     palindromeCheck(message, sizeof(message)/sizeof(int));
    //     write(client_socket, &message, sizeof(message));
    // }
i
    // if(read_size == 0){
    //     puts("Client disconnected");
    // }
    // else if(read_size==-1){
    //     puts("recv failed");
    // }
    for(;;){
        recv(client_socket, message, sizeof(message), 0);

        printf("The client's string is %s.\n", message);
        if(strlen(message)==0){
            flag=1;
        }
        else flag = palindromeCheck(message, strlen(message));

        send(client_socket, &flag, sizeof(int), 0);
        break;
    }
    close(socket_desc);
    return 0;
}
int palindromeCheck(char string[], int len)
{
    int i=0, j=len-1;
    while(i<j){
        if(string[i]==string[j]){
            i++, j--;
        }
        else {
            return 0;
        }
    }
    return 1;
}