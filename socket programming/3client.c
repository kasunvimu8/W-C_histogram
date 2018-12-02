/* Sample UDP client */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr;
	char sendline[] = "Hello UDP server! This is UDP client";
	char sendline1[]="Hello this is exercise 2";
	
	char sendline2[100];
	strcpy(sendline2,argv[2]);

	char recvline[1000];

	if (argc <= 3)
	{
	printf("usage: <IP address> <number of inetegers> <n>\n");
	return -1;
	}
	
	int inputs=atoi(argv[2]);
	
	if(inputs+3 != argc){
		printf("wrong number of inputs \n");
		
	return -2;	
		}

	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);
    
    sendto(sockfd,sendline2,strlen(sendline2),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
	recvline[n]=0;
	printf("Received  %s\n",recvline);
	
	for(int i=3;i<argc;i++){
		
		strcpy(sendline2,argv[i]);
		sendto(sockfd,sendline2,strlen(sendline2),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
		n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
		recvline[n]=0;
		printf("Received  input %d: %s\n",i-2,recvline);
		
		}
	
	printf("\n");
	return 0;
}
