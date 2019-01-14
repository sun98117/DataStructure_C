#include <stdio.h>

int main()
{
	int arr[10] = { 2, 5, 3, 1 };
	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (max < arr[i])
			max = arr[i];

	}
	printf("max number = %d\n", max);

	return 0;
}