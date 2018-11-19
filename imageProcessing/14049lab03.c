#include <stdio.h>
int main(){
int rows,colums,x,y,z,r,g,b,p;

scanf("%d %d",&colums,&rows);
printf("%d %d \n",rows,colums);
p= ((4-(3*colums)%4)%4); 


for(x=1 ; x<=rows;x++){
      for(y=1;y<=colums;y++){
      scanf("%d %d %d",&r,&g,&b);
       r= 255-r;
       g=255-g;
       b=255-b;
       printf("%d %d %d \n",r,g,b);
        }
  
     for(z=0;z<p;z++){
		 int p;
		scanf("%d",&p);
	    printf("0\n");
	    }
  

}

return 0;
}
