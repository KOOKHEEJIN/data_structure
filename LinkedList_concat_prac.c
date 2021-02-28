/*2개의 리스트 병합*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int element;
typedef struct {
	element data;
	struct LinkedList* link;
}LinkedList;

//insert
LinkedList* insert(LinkedList* head, element number) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = number;
	if (head == NULL) {
		p->link = NULL;
		head = p;
	}
	else {
		LinkedList* tmp = head;
		while (true) {
			if (tmp->link == NULL) {
				p->link = tmp->link;
				tmp->link = p;
				break;
			}
			tmp = tmp->link;
		}
	}
	return head;
}

//concat
LinkedList* concat_node(LinkedList* head1, LinkedList* head2) {
	for (LinkedList* tmp = head1; tmp != NULL; tmp = tmp->link) {
		if (tmp->link == NULL) {
			tmp->link = head2;	//list1의 맨 뒤 노드와 list2의 맨 앞 노드 연결
			break;
		}
	}
	return head1;
}

//print
void print_list(LinkedList* head) {
	for (LinkedList* p = head; p != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedList* head1 = NULL;
	LinkedList* head2 = NULL;
	element input1, input2;
	for (int i = 0; i < 5; i++) {
		printf("List1의 data 입력: ");
		scanf_s("%d", &input1);
		head1 = insert(head1, input1);
	}
	printf("===============================\n");
	for (int i = 0; i < 5; i++) {
		printf("List2의 data 입력: ");
		scanf_s("%d", &input2);
		head2 = insert(head2, input2);
	}
	head1 = concat_node(head1, head2);
	print_list(head1);

	return 0;
}