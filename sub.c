#include <stdio.h>
int sub(int n) {
	int result = 0;
	for (n; n > 0;) {
		result += n;
		n = n - 3;
	}
	return result;
}

int main()
{
	printf("%d\n",sub(10));

	return 0;
}
