#include <stdio.h>
extern int sum(int n);
extern double div(double n);
extern int fib(int n);
extern int sum2(int n);
extern int binomial_coefficient(int n, int k);
extern int binomial_coefficient2(int n, int k);
int main()
{
	printf("%d\n", binomial_coefficient2(4,2));
	return 0;
}