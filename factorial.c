#include <stdio.h>

int factorial(int n) {
	printf("factorial(%d)\n", n);
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int factorial_(int n) {
	int result = 1;
	for (int i = n; i>0; i--) {
		result *= i;
	}
	return result;
}

int main() {
	int n = 3;
	factorial(n);
	printf("factorial_ : %d\n", factorial_(n));

	return 0;
}