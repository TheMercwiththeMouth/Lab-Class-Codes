#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc, char* argv[])
{
  int socketfd, i, temp;
  struct sockaddr_in sa;

  int n;
  printf("Enter the number of elements of your input array to be sorted:\n");
  scanf("%d", &n);
  int server_reply[n];
  int inputarray[n];
  printf("Dear client, please input %d numbers:\n", n);
  for(int i=0; i<n; i++){
    int val;
    scanf("%d", &val);
    inputarray[i]=val;
  }

  printf("The input array is:\n");
  for(int i=0; i<n; i++){
    printf("%d ",inputarray[i]);
  }
  
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

 if (send(socketfd, &inputarray, n*sizeof(int), 0) < 0) {
        puts("Send failed");
        return 1;
    }
 
    // Receive a reply from the server
    if (recv(socketfd, &server_reply, n*sizeof(int), 0) < 0) {
        puts("recv failed");
        return 0;
    }

 puts("Server reply:\n");
 for(int i=0; i<n; i++){
    printf("%d\n", server_reply[i]);
 }

 close(socketfd);
 return 0;
}