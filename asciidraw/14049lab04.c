#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}





int main(int argc, char **argv){
int x1,x2,x3;
x1=strcmp(argv[1],"checker") && strcmp(argv[1],"donut");
if(x1!=0)
  {printf("Requested figure is not available\n");
   return;
  }

x2=strcmp(argv[2],"black")&&strcmp(argv[2],"blue")&&strcmp(argv[2],"green")&&strcmp(argv[2],"red")&&strcmp(argv[2],"yellow")&&strcmp(argv[2],"magenta")&&strcmp(argv[2],"cyan")&&strcmp(argv[2],"white");

if(x2!=0){
  printf("Background color is not available\n");
    return;
    }
x3=strcmp(argv[3],"black")&&strcmp(argv[3],"blue")&&strcmp(argv[3],"green")&&strcmp(argv[3],"red")&&strcmp(argv[3],"yellow")&&strcmp(argv[3],"magenta")&&strcmp(argv[3],"cyan")&&strcmp(argv[3],"white");
if(x3!=0){
printf("Foreground color is not available\n");
    return;
    }


 int color1,color2;
if (strcmp(argv[2],"black")==0)
  color1=0;
else if(strcmp(argv[2],"red")==0)
  color1=1;
else if(strcmp(argv[2],"green")==0)
  color1=2;
else if(strcmp(argv[2],"yellow")==0)
  color1=3;
else if(strcmp(argv[2],"blue")==0)
  color1=4;
else if(strcmp(argv[2],"magenta")==0)
  color1=5;
else if(strcmp(argv[2],"cyan")==0)
  color1=6;
else if(strcmp(argv[2],"white")==0)
  color1=7;
else {}

if (strcmp(argv[3],"black")==0)
  color2=0;
else if(strcmp(argv[3],"red")==0)
  color2=1;
else if(strcmp(argv[3],"green")==0)
  color2=2;
else if(strcmp(argv[3],"yellow")==0)
  color2=3;
else if(strcmp(argv[3],"blue")==0)
  color2=4;
else if(strcmp(argv[3],"magenta")==0)
  color2=5;
else if(strcmp(argv[3],"cyan")==0)
  color2=6;
else if(strcmp(argv[3],"white")==0)
  color2=7;
else {}

if(strcmp(argv[1],"donut")==0){
    int diameter,r,i,j;
scanf("%d",&diameter);//get the use input diameter
r=diameter/2;

for (i=1;i<= diameter; i++){ // going through y axis
	for(j=1 ; j <= diameter ; j++) { //going through x axis

	if(((i - r)*( i -r)+ ( -j+ r) *(-j + r) -(r*r)) <  0)
        { //outer circle print
    if (((i - r)*( i -r)+ ( -j+ r) *(-j + r))-((r*r)/4)< 0 )
    { // inner circle
        textcolor(1,color2,color1);
         printf(" ");
			}
			else{
				 textcolor(1,color1,color2);
                printf(" ");
				}
				}
				else{
		printf(" ");
		}
		}
	printf("\n");
	}

}


	if (strcmp(argv[1],"checker")==0){
int a,b,c,d,e=1,f;
    for(f=1;f<=8;f++ ){ // print down 8 boxes rows
for(a=1;a<=8;a++){ //print one row, 8 column boxes
  for(b=1;b<=8;b++){//take 1 box in a particular column
            if(e==0){
					for(c=0;c<8;c++){ //print colors in a particular box
						 textcolor(1,color2,color1);
                          printf(" ");
					}
					e=e+1;
				}else{
					for(c=0;c<8;c++){
						 textcolor(1,color1,color2);
                         printf(" ");
					}
				e=e-1;
				}



    }
     printf("\n");



 }
if(e==1){
    e=e-1;
}
else{
    e=e+1;
}
    }
}



	textcolor(RESET, WHITE, BLACK);
	return 0;


}
