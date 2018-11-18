
#include <stdio.h>
int main(){
	char a,b;

	scanf("%c %c",&a,&b);

	if( (b=='P'|b=='R' |b =='C' |b=='S' |b=='L') ){
		if(a==b){ 
			printf("Tie\n");
			//return 0;
			}
		else{
			if((a == 'R') & (b == 'C'| b=='L' )){
				printf("Player 1 wins\n");
				//return 0;
				}
			else{
				if((a == 'P') & (b == 'R' |b== 'S' )){
					printf("Player 1 wins\n");
					//return 0;
					}
				else{
					if((a == 'C') & (b == 'P' |b== 'L')){
						printf("Player 1 wins\n");
						//return 0;
						}
						else{
							if((a == 'S') & (b == 'C' |b== 'R')){
								printf("Player 1 wins\n");
								//return 0;
								}
								else{
									printf("Player 2 wins\n");
									//return 0;
									}
							}
					}
				}
			}
		
		}
	else{
			printf("Wrong Input\n");
			}
	
	return 0;
}
