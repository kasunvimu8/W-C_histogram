#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node //hold the word
{
char word[100];
int  repit;
int wordsize; 
double per,dotsize;

struct node* next;
}node_t;


typedef struct node1{// hold the character
char ch;	
double size,dotsize;
	
struct node1* next;	
}char_node;

	
void printdot(int x);
void frontprint(int max);
void topandbotom(int x,int y);
void rest(int max);

int main(int argc,char **argv ){
	
	int n=10,scaled=0,wmode=1,argccount=0;
	
	node_t *current=NULL;
	node_t *current1=NULL;
	node_t *current2=NULL;
	node_t *head=NULL;	
	char_node *char_current=NULL;
	char_node*char_head=NULL;

    int count=0;
    
    if(argc ==1){
		printf("No input files were given\nusage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
		return 1;
	}
	
	else {
		
		for(int i=0;i<argc;i++){
			
			if(strcmp(argv[i],"-c")==0){			
			wmode=0;
			argccount++;	
			}
			if(strcmp(argv[i],"-w")==0){
			argccount++;	
			}
			
			
			if(strcmp(argv[i],"-l")==0){		
				n=atoi(argv[i+1]);
				
				 for(int j=0;j<strlen(argv[i+1]);j++){
					
					if(! isdigit(argv[i+1][j])){
						printf("Invalid option for [%s]\nusage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[i]);
			        	return 1;
						
					}
				
					
				 }		
			
				i++;
				argccount=argccount+2;	
			}
		
			if((strcmp(argv[i],"--scaled")==0)){
			scaled=1;
			argccount++;	
			}
			
			
			if(argv[i][0]=='-'){
				if((strcmp(argv[i],"--scaled")!=0) && (strcmp(argv[i],"-c")!=0) && (strcmp(argv[i],"-l")!=0) && (strcmp(argv[i],"-w")!=0)){
				printf("Invalid option for [%s]\nusage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[i]);
				return 1;
				}
						        
	    	}
			
			if(argc-argccount-1==0){		
			printf("No input files were given\nusage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
			return 1;
			
			}			
			
		}
	
	
	}
   

for(int i=1;i<=argc-argccount-1;i++){   
FILE *ifp;
ifp=fopen(argv[i],"r");

if(ifp ==NULL){
	printf("Cannot open one or more given files\n");
	return 0;
	}
 
while(!feof(ifp)){
	char chararray[100]={0};
	int c;	

		if(head==NULL){
		current=(node_t*)malloc(sizeof(node_t));
		fscanf(ifp,"%s",chararray);
		c=0;	
  
			for(int i=0;chararray[i] !='\0';i++){
	 
					if((chararray[i] >='a'&&chararray[i]<='z') ||(chararray[i]>='A'&&chararray[i]<='Z') || (chararray[i] >='0'&&chararray[i]<='9') ){
			
						if(isupper(chararray[i])){
				
							chararray[i]=chararray[i]-'A'+'a';
				
						}
			
			
					  c++;
					}
 
			}

			if (c!=0){
			strcpy(current->word,chararray);
			count++;
			head=current; 
		
			}
    
		}
	
	
		else{
			c=0;
	
			fscanf(ifp,"%s",chararray);
	
			for(int i=0;chararray[i] !='\0';i++){
	 
					if((chararray[i] >='a'&&chararray[i]<='z') ||(chararray[i]>='A'&&chararray[i]<='Z') || (chararray[i] >='0'&&chararray[i]<='9') ){
					
						if(isupper(chararray[i])){
				
						chararray[i]=chararray[i]-'A'+'a';
				
						}
					
					
						c++;
					}
 
			}
								
				if (c!=0){
					current->next=malloc(sizeof(node_t));
					current=current->next;
					strcpy(current->word,chararray);
					
					
					
					count++;
				}
	
		}

}
fclose(ifp);
}

current->next=NULL;  // assign null after terminating 


int array[36]={};
int charcount=0;
current=head;
while(current!=NULL){
	
	for(int i=0;i<strlen(current->word);i++){
		  
				if(((current->word)[i]>='a' && (current->word)[i]<='z')){
			   
						array[(current->word)[i]-'a']++;   
						charcount++;			   			   
				}
		    		    
				else if((current->word)[i]>='0' && (current->word)[i]<='9'){
				
				array[(current->word)[i]-'0'+26 ]++;
				charcount++;
							
				}
						
	}
	
	current=current->next;
		
}


int index;
double percet;
for(int i=0;i<36;i++){ 
	int max= 0;
	
		for(int j=0;j<36;j++){
				if(array[j]>max) {
					max=array[j];
					index=j;
				}
		}
	
		percet=(100.00*max)/charcount ;
										
		if(index<26){
	
		
			if (char_head== NULL){
	
			char_current=(char_node*)malloc(sizeof(char_node));
			char_current->ch='a'+index;
			char_current->size=percet;
			char_head=char_current; 
	
			}
	
			else{ 
			
			char_current->next=(char_node*)malloc(sizeof(char_node));
			char_current=char_current->next;
			char_current->ch='a'+index;
			char_current->size=percet;
		
			}
		
			array[index]=0;
		}
	
		else{
	
	
			if (char_head== NULL){
	
			char_current=(char_node*)malloc(sizeof(char_node));
			char_current->ch='0'+index-26;
			char_current->size=percet;
			char_head=char_current; 
        	
			}
	
			else{ 
			
			char_current->next=(char_node*)malloc(sizeof(char_node));
			char_current=char_current->next;
			char_current->ch='0'+index-26;
			char_current->size=percet;
		
			}
	
	
			array[index]=0;			
		}
	
}

char_current->next=NULL;


current=head;
while(current!=NULL){
		for(int i=0;(current->word)[i] !='\0';i++){
			while(!(((current->word)[i] >='a'&&(current->word)[i]<='z') ||((current->word)[i] >='A'&&(current->word)[i]<='Z') || ((current->word)[i] >='0'&&(current->word)[i]<='9') ||(current->word)[i]=='\0'  )){
				int j;
					for(j=i;(current->word)[j] !='\0';j++){
				
					(current->word)[j]=(current->word)[j+1];
				
					}
				
				(current->word)[j]='\0';
			
			}
		
		
		}

current=current->next;
	
}


current1=head;
while(current1!=NULL){
	    
	    current2=head;
	    int size=0;
			while(current2!=NULL ){
				if(strcmp(current1->word,current2->word)==0){
					current2->repit=0;
					size++;
				}
     	
				current2=current2->next;
			}
	
	current1->repit=size;			 
	current1=current1->next;
}

	
int done=1;
while(done){
done=0;
		char tempword[100]={0};
		int temprepit;
	    current=head;
			while(current->next != NULL ){
				 if((current->repit)<(current->next->repit)) {
					 done=1;		   
					 strcpy(tempword,current->word);
					 temprepit=current->repit;
						
					 strcpy(current->word,current->next->word);
					 current->repit =current->next->repit;
									  
					 strcpy(current->next->word,tempword);
					 current->next->repit=temprepit;   
				
				  }
     	
				current=current->next;
		    }
	
}
	
	
int maxWord=0,i=0;
current = head;
	while(i<n){ 
		
		current->wordsize = strlen(current->word);
			if(maxWord<current->wordsize){
				maxWord = current->wordsize;
			}
		current = current->next;
		i++;
	}	
	
//*******************************************

double factor;
if(wmode){
	current = head;
	i=0;
	while(i<n){
	
			topandbotom(maxWord,current->dotsize);//print the top and bottom
			
			current->per = 100.00*(current->repit)/(count);	
			current->dotsize = current->per*(80-maxWord-8)/100.00;
			
			if(current==head){
				factor = (80-maxWord-8)/(head->dotsize);
			}
			
			if(scaled){
			current->dotsize=current->dotsize*factor;
				
				}
			
			
			for(int i=0;i<(maxWord+2);i++){ //print the space after the word
				printf(" ");
			}
    
			printf("\u2502"); //print the | line
			printdot(current->dotsize);
			printf("\n");
			printf(" %s",current->word);
					
			for(int i=0;i<(maxWord- (current->wordsize)+1);i++){ //print the space after the word
				printf(" ");
			}
    
			printf("\u2502"); //print the | line
			printdot(current->dotsize);
			printf("%0.2f%%\n",current->per);
			topandbotom(maxWord,current->dotsize);
			frontprint(maxWord);
	
			printf("\n");
			current = current->next;
			i++;
	}	

	rest(maxWord);
}
//******************************************
else{
	
	char_current = char_head;
    i=0;
	while(i<n){
		maxWord=1;
	
		topandbotom(maxWord,char_current->dotsize);//print the top and bottom	
		
		char_current->dotsize = char_current->size*(80-maxWord-8)/100.00;
	
	
	
	 if(char_current==char_head){
				factor = (80-maxWord-8)/(char_head->dotsize);
			}
			
			if(scaled){
			char_current->dotsize=char_current->dotsize*factor;
				
				}
	
		printf("   ");
		printf("\u2502"); //print a | line
		printdot(char_current->dotsize);
		printf("\n");
		printf(" %c",char_current->ch);		
		printf(" ");
    
		printf("\u2502"); //print a | line
		printdot(char_current->dotsize);
		printf("%0.2f%%\n", char_current->size);
		topandbotom(maxWord,char_current->dotsize);
	
		frontprint(maxWord);
	
		printf("\n");
		char_current = char_current->next;
		i++;
	}	

	rest(maxWord);
}
	
return 0;
}



void printdot(int x){
	for(int i=0;i<x;i++){
			printf("\u2591"); //print the dots
		}
	
	}


void topandbotom(int x,int y){
	
	frontprint(x);
	printdot(y);
	printf("\n");
	
}


void frontprint(int max){
	
	for(int i=0;i<(max+2);i++){
			printf(" ");
		}
		printf("\u2502");  //print connected |
}
	
		
void rest(int max){
	
	for(int x=0;x<(max+2);x++){
			printf(" ");
	}
	printf("\u2514");
	
	for(int i=0;i<(80-max-3);i++){
		printf("\u2500");
	}
	printf("\n");
		
	}
