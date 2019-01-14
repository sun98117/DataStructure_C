#include <stdio.h>
#define MAX_LIST_SIZE 100
typedef int element;

typedef struct {
	element list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

void init(ArrayListType * L) {
	L->length = 0;
}
int is_empty(ArrayListType * L) {
	return L->length == 0;
}
int is_full(ArrayListType* L) {
	return L->length > MAX_LIST_SIZE;
}
void array_display(ArrayListType* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\n", L->list[i]);
	}
}
void add(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->length)) {
		for (int i = (L->length - 1); i >= pos; i--)
			L->list[i + 1] = L->list[i];
		L->list[pos] = item;
		L->length++;
	}
}
element delete(ArrayListType* L, int pos) {
	int i;
	element item;
	if (pos < 0 || pos >= L->length)
		error("위치 오류");
	item = L->list[pos];
	for (i = pos; i < (L->length - 1); i++) {
		L->list[i] = L->list[i + 1];
	}
	L->length--;

	return item;
}
void clear(ArrayListType* L) {
	L->length = 0;
}
void replace(ArrayListType* L, int pos, element item) {
	if (pos > L->length || pos < 0)
		error("위치 오류");
	L->list[pos] = item;
}
element get_entry(ArrayListType* L, int pos) {
	return L->list[pos];
}
int get_length(ArrayListType* L) {
	return L->length;
}
/*int main() {
	ArrayListType list1;
	ArrayListType *plist;
	//정적 생성
	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);

	display(&list1);
	printf("%d\n",get_length(&list1));
	//동적 생성
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 30);
	add(plist, 0, 20);
	add(plist, 0, 10);
	display(plist);
	free(plist);

	return 0;
}*/