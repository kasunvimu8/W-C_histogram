
/* Sample UDP server */
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char**argv){

	char s[100];
     int rc;
     time_t temp;
     struct tm *timeptr;

	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mesg[1000];
	char* banner = "Hello UDP client! This is UDP server";
	
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);	//create a socket
	
	servaddr.sin_family = AF_INET;	//address family	
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);	//IP address in the network byte order
	servaddr.sin_port=htons(32000);
	
	while(1){
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	
	n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
	
	while(1){
		temp = time(NULL);
	    timeptr = localtime(&temp);

	    rc = strftime(s,sizeof(s),"Time:  %r", timeptr);
	    //printf("%s\n",s);

		sendto(sockfd,s,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		mesg[n] = 0;
		sleep(1); 
	}
	

	}
	
	return 0;
}
