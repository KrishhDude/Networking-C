#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <unistd.h>
#define BUF_SIZE 256
int main(int argc,char* argv[])
{
     struct sockaddr_in server,client;
     char str[50],msg[20];
     if(argc!=2)
     printf("Input format not correct");
     int sockfd=socket(AF_INET,SOCK_DGRAM,0);
     if(sockfd==-1)
     printf("Error in socket();");
     server.sin_family=AF_INET;
     server.sin_addr.s_addr=INADDR_ANY;
     server.sin_port=htons(atoi(argv[1]));
     client.sin_family=AF_INET;
     client.sin_addr.s_addr=INADDR_ANY;
     client.sin_port=htons(atoi(argv[1]));
     bind(sockfd,(struct sockaddr *)&server,sizeof(server));
     socklen_t client_len=sizeof(client);
     printf("server waiting......");
     sleep(3);
     memset(msg, '\0', sizeof msg);
     recvfrom(sockfd,str,100,0,(struct sockaddr *)&client,&client_len);
     if(sendto(sockfd,str,sizeof(str),0,(struct sockaddr *)&client,sizeof(client))<0)
     printf("Error in send");
     sleep(15);

     
     recvfrom(sockfd,msg,sizeof(str),0,(struct sockaddr *)&client,&client_len);
     printf("mail body received");
     printf("\n%s",msg);

     
     if(strncmp(str,"QUIT",4))
     printf("quit expected from client....");
     printf("\nSending quit...");
     
     close(sockfd);
     return 0;
}