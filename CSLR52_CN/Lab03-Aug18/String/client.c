#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc, char* argv[])
{
  int socketfd, i, temp;
  struct sockaddr_in sa;

  int flag;
  int server_reply;
  char inputstring[100];
  printf("Dear client, please input the string to be evaluated:\n");
  scanf("%s", inputstring);

  printf("Your input string is %s\n", inputstring);
  
  // creates the socket
  socketfd=socket(AF_INET,SOCK_STREAM,0);
  if(socketfd ==-1){
    printf("Could not create the socket");
  }
  puts("Socket Created");

  sa.sin_family=AF_INET;
  sa.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa.sin_port=htons(8356);


 if(connect(socketfd, (struct sockaddr*)&sa, sizeof(sa))<0){
    perror("Connect failed. Error");
    return 1;
 }
 puts("Connected\n");

 if (send(socketfd, inputstring, sizeof(inputstring), 0) < 0) {
        puts("Send failed");
        return 1;
    }
 
    // Receive a reply from the server
    if (recv(socketfd, &server_reply, sizeof(int), 0) < 0) {
        puts("recv failed");
        return 0;
    }

    if(server_reply==1){
        printf("String is a palindrome");
    }
    else printf("String is not a palindrome");

 

 close(socketfd);
 return 0;
}