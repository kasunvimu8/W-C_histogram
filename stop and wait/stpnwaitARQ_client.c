/* Sample UDP client */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0


int main(int argc, char**argv){
	
	int sockfd,n,x;
	int j=0;
	int y;
	bool canSend=true;
	struct sockaddr_in servaddr;
	//char sendline[] = "Hello UDP server! This is UDP client";
	char sendline[] = "Hello !";
	char recvline[1000];
		char recvack[1000];
		char recvupper[1000];
	
	if (argc != 2){
		printf("usage:%s <IP address>\n",argv[0]);
		return -1;
	}
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);
	struct timeval tv = {5, 0};
setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv, sizeof(struct timeval));

	printf("print number\n");
	char number[10];
	char sentence[1000];
	scanf("%s",number);
	int num;
	num=atoi(number);
	int a=0;
	do{
		sendto(sockfd,number,strlen(number),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
		x=recvfrom(sockfd,recvack,10000,0,NULL,NULL);
	
    }while(x<=0 && strcmp(recvack,"ack")!=0 );

	recvack[x]=0;
	printf("Received: %s\n",recvack);

	printf("enter the sentences\n");

	fgets (sentence, 1000, stdin);
	for(j=0;j<num;j++){
		scanf("%[^\n]%*c",sentence);
		char c[4];
		if(j%2==0){
			strcpy(c,"ack1");
		}
		if(j%2==1){
			strcpy(c,"ack0");
		}
		
	    sendto(sockfd,sentence,strlen(sentence),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
	    do{
			setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv, sizeof(struct timeval));	
			x=recvfrom(sockfd,recvack,10000,0,NULL,NULL);
		}while(x<=0 && strcmp(recvack,c)!=0 );
	
		recvack[x]=0;
		y=recvfrom(sockfd,recvupper,10000,0,NULL,NULL);
		recvupper[y]=0;
	
		printf("Received: %s\n",recvack);
		printf("Received: %s\n",recvupper);
	}
		
		return 0;
	}