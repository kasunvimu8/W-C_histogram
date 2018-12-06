/* Sample UDP client */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char**argv){
	int sockfd,n;
	struct sockaddr_in servaddr;
	char sendline[1000] ;
	char recvline[1000];
	int sentences=0,count=0;
	int windowSize=4;
	struct timeval timeout={2,0}; //set timeout for 2 seconds
	
	/* set receive UDP message timeout */

	setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(struct timeval));

	if (argc != 3){
		printf("usage:%s <IP address> <number of messages> \n",argv[0]);
		return -1;
	}

	sentences=atoi(argv[2]);
	strcpy(sendline,argv[2]);
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);

	sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

	n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);

	recvline[n]=0;
	
	printf("Received: %s\n",recvline);
	char messages[sentences][1000] ;
	

	int i,j;
	for(i=0;i<sentences;i++){			
		printf("Client message %d - " ,i);
		scanf("%s",messages[i]);
	}
	
	for(i=0;i<sentences;i+4){
		for(j=i;j<i+4;j++){
			strcpy(sendline,messages[j]);
			sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
			n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
			recvline[n]=0;
			printf("Received (from server) : %s\n",recvline);
			
		  char * reply=strtok (recvline," ");
		
			
			if(strcmp(reply,"nak")){
        reply = strtok (NULL, " ");
				sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
				n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
			}
		}
	}
	
	return 0;
}
