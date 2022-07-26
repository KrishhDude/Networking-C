#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include"time.h"
int main()
{
	int welcomeSocket,newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	
	time_t tick;
	welcomeSocket=socket(AF_INET,SOCK_DGRAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
	bind(welcomeSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
	if(listen(welcomeSocket,5)<0)
		printf("Listening\n");
	else
		printf("Error\n");
	addr_size=sizeof serverStorage;
	int n;
	recvfrom(welcomeSocket,buffer,1024,0,(struct sockaddr *)&serverStorage,&addr_size);
	printf("%s",buffer);
	printf("ipaddress of client is %s\n",buffer);
	return 0;
}
