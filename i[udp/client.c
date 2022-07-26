#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
	int clientSocket,n;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	//struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	clientSocket=socket(AF_INET,SOCK_DGRAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
	addr_size=sizeof(serverAddr);
	strcpy(buffer,inet_ntoa(serverAddr.sin_addr));
	
	sendto(clientSocket,buffer,1024,0,(struct sockaddr *)&serverAddr,addr_size);
	printf("%s",buffer);
	printf("\nIP address of client send to server\n");
    	return 0;
}
