/* Sample UDP server */
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char**argv){
	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mesg[1000];
	int nextFrame=1;
	int sentences=0;
	char* banner = "ack";
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);	//create a socket
	
	servaddr.sin_family = AF_INET;	//address family	
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);	//IP address in the network byte order
	servaddr.sin_port=htons(14194);
	
	
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	
	while(1){
		
		n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
		sentences=atoi(mesg);

		sendto(sockfd,banner,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		mesg[n] = 0;
		printf("Received: %s\n",mesg);
		
		
		for(count=0;count<sentences;count++){
			char reply[5];
			n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
			printf("Received (from client) : %s\n",mesg);
			
			if(n>0){
				sprintf(reply, "%d", count);
				strcat("ack ",reply);
			}else{
				sprintf(reply, "%d", count);
				strcat("nck ",reply);
			}
			sendto(sockfd,reply,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
			mesg[n] = 0;
			
		}

	}
	return 0;
}


