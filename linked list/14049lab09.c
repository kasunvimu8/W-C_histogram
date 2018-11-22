#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
char word[20];
int  lenght; 
 
struct node* next;
}node_t;	



int main(int argc,char **argv ){
	node_t *current=NULL;
	node_t *head=NULL;
	node_t *maxaddress=NULL;
    int count=0;
    
FILE *ifp;
ifp=fopen(argv[1],"r");


while(!feof(ifp)){
	
	if(head==NULL){
 current=(node_t*)malloc(sizeof(node_t));
 fscanf(ifp,"%s",current->word);
 current->lenght=strlen(current->word);
 
   head=current; //keep head remember in head
   count++;
	}
	
	else{
	current->next=(node_t*)malloc(sizeof(node_t));
	current=current->next;
	fscanf(ifp,"%s",current->word);
	current->lenght=strlen(current->word);
	count++;
		}

}

current->next=NULL;

fclose(ifp); 
int i;
for(i=0;i<count;i++){
int maxvalue=0;
current=head;

while(current!=NULL){
	
	if((current->lenght)>maxvalue){
		maxaddress=current;
		maxvalue=(current->lenght);
		}
	current=current->next;
	
	}

printf("%s\n",maxaddress->word);
maxaddress->lenght=0;

}

return 0;
}
