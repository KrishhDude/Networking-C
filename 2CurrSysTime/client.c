#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
	int clientSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_Size;
	
	clientSocket = socket(PF_INET,SOCK_STREAM,0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));
	
	addr_Size=sizeof serverAddr;
	connect(clientSocket,(struct sockaddr *) &serverAddr,addr_Size);
	recv(clientSocket,buffer,1024,0);
	
	printf("Data Received: %s",buffer);
	return 0;
}
