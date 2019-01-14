#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* msg) {
	fprintf(stderr,"%s\n",msg);
	exit(1);
}

void insert_node(ListNode** phead, ListNode *p, ListNode* new_node) {//p : new_node앞 포인터
	if (*phead == NULL) { // 공백인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}
void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL) 
		*phead = (*phead)->link;
	
	else 
		p->link = removed->link;
	
	free(removed);
}
void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->link == NULL) {
			printf("%d\n",p->data);
		}
		else
			printf("%d->",p->data);
		p = p->link;
	}
}
ListNode* search(ListNode* head, int x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) 
			return p;
		p = p->link;
	}
	return p;
}
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}
ListNode* reverse(ListNode* head) {
	ListNode *p, *q, *r; //p : 처리하지 않은 노드, q : 현재 역순으로 만들 노드, r : 이미 역순으로 변경된 노드
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r; //링크의 방향을 바꾼다
	}
	return q;
}
ListNode *create_node(element data, ListNode* link) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("메모리할당 에러");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}
/*int main() 
{
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *p;
	
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);
	remove_node(&list1, NULL, list1);
	display(list1);

	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	list1 = concat(list1, list2);
	display(list1);

	list1 = reverse(list1);
	display(list1);

	p = search(list1, 20);
	printf("탐색성공 = %d\n", p->data);
	return 0;
}*/