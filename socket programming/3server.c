/* Sample UDP server */
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mesg[1000]={ };
	//char* banner = "Hello UDP client! This is UDP server";
	char banner[] = "ack";

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(32000);
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	

while(1){

	n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
	sendto(sockfd,banner,3,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	mesg[n]=0;
	int number=atoi(mesg);
	printf("Received: ");
	
	for(int i=0;i<number;i++){
		n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
		for(int j=0;j<strlen(mesg);j++){
			if(islower(mesg[j])){
				mesg[j]=mesg[j]-32;
				}
			
			
			}
		sendto(sockfd,mesg,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		mesg[n]=0;
			
		
		}
	
    }
	return 0;
}
