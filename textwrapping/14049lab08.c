/* WRAPPING TEXT - LAB 08 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv ){
FILE *ifp;

if(argc!=3){
   printf("Usage: %s <width> <input-file>\n",argv[0]);
   return 0;
           }
int width= atoi(argv[1]); 
char word[100]; 
int max=0;
        
ifp=fopen(argv[2],"r"); // open the file

while(fscanf(ifp,"%s",word)!= EOF){ //reads the file to check,
int lenght=strlen(word);          //longest word exceed width or not
   if(max<lenght){
	   max=lenght;
		   }
	}
	
if(max>width){
printf("Word length must be less than screen width\n");	
   return 0;
    }
fclose(ifp); //close the file  
 
 
ifp=fopen(argv[2],"r"); // open the file   	
char character;
int wrapplenght=0;

while(fscanf(ifp,"%s%c",word,&character)!= EOF){
int	wordlenght=strlen(word);
	wrapplenght+=wordlenght;
	
	if(wrapplenght>width){ //word doesn't break go for new line
	printf("\n");
	wrapplenght=wordlenght;	
		}
		
    printf("%s ",word);//print the word
    wrapplenght++; //to increase the wrapplenght because of character(space)
	
	if(character=='\n'){    
	printf("\n");
	wrapplenght=0;
		}
	
	
	if(wrapplenght==width){
	printf("\n");
	wrapplenght=0;	
		}
		
}
fclose(ifp); //close the file
}
