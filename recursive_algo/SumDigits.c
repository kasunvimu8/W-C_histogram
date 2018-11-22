// Week10_SumDigits.c
// Sum up all digits in an integer.

#include <stdio.h>

int sum_digits(int);

int sumArray(int [], int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);

	printf("Sum of its digits = %d\n", sum_digits(num));

	return 0;
}

// Return sum of digits in integer n
// Pre-cond: n >= 0
int sum_digits(int n) {
	int k=n%10;
	int p=n/10;
	
	if (k ==0 && p==0) return 0;
	
	return k+ sum_digits(p);
}

