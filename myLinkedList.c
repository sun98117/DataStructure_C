#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode* link;
}ListNode;
ListNode* mycreate(element data, ListNode* link) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = link;
	return p;
}
void myInsert(ListNode **phead, ListNode* p, ListNode *new_node) {
	if (*phead == NULL) { //공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { //첫번째노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}
void myRemove(ListNode **phead, ListNode *p, ListNode *removed) {
	if (p == NULL) //첫번째 노드 삭제
		*phead = removed->link;
	else 
		p->link = removed->link;
	
	free(removed);
}
void myDisplay(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}
ListNode* mysearch(ListNode *head, element d) {
	ListNode* p = head;
	while (p->link == NULL) {
		if (p->data == d)
			return p;
		p = p->link;
	}
	return p;
}
ListNode* myConcat(ListNode* list1, ListNode* list2) {
	ListNode* p;
	if (list1 == NULL) return list2;
	else if (list2 == NULL) return list1;
	else {
		p = list1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = list2;
		return list1;
	}
}
ListNode* myReverse(ListNode* head) {
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main()
{
	ListNode *list1 = NULL;
	ListNode *p;
	myInsert(&list1, NULL, mycreate(10, NULL));
	myInsert(&list1, NULL, mycreate(20, NULL));
	myInsert(&list1, NULL, mycreate(30, NULL));
	myDisplay(list1);


	return 0;
}