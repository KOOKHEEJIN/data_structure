/*단순 연결리스트 역순으로 만들기*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 5

typedef int element;
typedef struct {
	element data;
	struct LinkedList* link;
}LinkedList;

LinkedList* find_pre(LinkedList* head, LinkedList* node) {
	LinkedList* pre = head;
	if (!pre) {
		printf("메모리가 부족합니다.\n");
		exit(1);
	}
	while (true) {
		if (pre->link == node) {
			break;
		}
		pre = pre->link;
	}
	return pre;
}

int not_same(LinkedList* head, int max) {
	int number;
	bool is_same = false;
	while (true) {
		number = rand() % max + 1;
		for (LinkedList* node = head; node != NULL; node = node->link) {
			if (node->data == number) {
				is_same = true;
				break;
			}
		}
		if (is_same == false) break;
	}
	return number;
}

LinkedList* insert(LinkedList* head, element number) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (!p) {
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	p->data = number;
	
	if (head == NULL) {
		p->link = NULL;
		head = p;
		return head;
	}
	for (LinkedList* tmp = head; tmp != NULL; tmp = tmp->link) {
		if (tmp->data > p->data) {
			if (tmp == head) {
				p->link = tmp;
				head = p;
			}
			else {
				LinkedList* pre = find_pre(head, tmp);
				p->link = tmp;
				pre->link = p;
			}
			break;
		}
		else {
			if (tmp->link == NULL) {
				p->link = NULL;
				tmp->link = p;
				return head;
			}
		}
	}
	return head;
}

LinkedList* reverse(LinkedList* head) {
	LinkedList* node, * new_node, * pre;
	node = head;
	new_node = NULL;
	while (true) {
		if (node == NULL) break;
		pre = new_node;
		new_node = node;
		node = node->link;
		new_node->link = pre;
	}
	return new_node;
}

void print_list(LinkedList* head) {
	for (LinkedList* node = head; node != NULL; node = node->link) {
		printf("%d-> ", node->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedList* head = NULL;
	element input;
	srand((unsigned int)time(NULL));


	for (int i = 0; i < MAX; i++) {
		input = not_same(head, 100);
		head = insert(head, input);
		//print_list(head);
	}

	printf("============Before===========\n");
	print_list(head);

	head = reverse(head);

	printf("\n============After============\n");
	print_list(head);


	return 0;
}
