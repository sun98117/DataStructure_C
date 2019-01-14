#include <stdio.h>
double div(double n) {

	if (n < 1) return 0;
	else {
		printf("%lf\n", 1 / n);
		return (1 / n) + div(n - 1);
	}
}