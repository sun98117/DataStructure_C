#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
typedef int element;
typedef struct{
	element arr[MAX_LEN];
	int length;
}ARRAY;
void myinit() {
	ARRAY a;
	a.length = 0;
}
int myis_empty(ARRAY a) {
	if (a.length == 0)
		return 1;
	else
		return 0;
}
int myis_full(ARRAY a) {
	if (a.length == MAX_LEN)
		return 1;
	else
		return 0;
}
void mydisplay(ARRAY a) {
	int i = 0;
	do {
		printf("%d ", a.arr[i]);
		i++;
	} while (i != a.length);
	printf("\n");
}
void myadd(ARRAY a, int n) {
	if (myis_full(a))
		return;
	else {
		a.arr[a.length] = n;
		a.length++;
	}
}
element mydelete(ARRAY a, int num) {
	if (num > a.length)
		return -1;
	else {

	}
}
