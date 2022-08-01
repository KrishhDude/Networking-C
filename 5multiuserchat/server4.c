#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
	int welcomeSocket,newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	
	time_t tick;
	welcomeSocket=socket(PF_INET,SOCK_STREAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
	bind(welcomeSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
	if(listen(welcomeSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");
	addr_size=sizeof serverStorage;
	while(newSocket=accept(welcomeSocket,(struct sockaddr *)&serverStorage,&addr_size)){
		int pid;
		if((pid=fork())==0){
			while(recv(newSocket,buffer,100,0)>0){
				printf("Message Recieved:%s\n",buffer);
				memset(buffer,'\0',sizeof buffer);
			}
			exit(0);
		}
	}
	return 0;
}
