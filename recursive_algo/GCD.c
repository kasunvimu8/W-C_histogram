// Week10_GCD.c
// Compute the greatest common divisor (GCD) of two
// non-negative integers, not both zero.
#include <stdio.h>

int gcd(int, int);

int main(void) {
	int num1, num2;

	printf("Enter two integers: ");
	scanf("%d %d", &num1, &num2);

	printf("gcd(%d, %d) = %d\n", num1, num2, gcd(num1, num2));
	return 0;
}

// Compute the greatest common divisor of a and b
// Precond: a and b non-negative, not both zero
int gcd(int a, int b) {
	// to be completed
	int k,p;
	
	if (a<b){
		k=a;
		a=b;
		b=k;
		}
		
	if(b==0) return a;
	
	else{
		p=a%b;
		a=b;
		b=p;
		return gcd(a,b);
		
		}


}

