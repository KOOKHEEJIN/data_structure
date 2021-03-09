/*연결리스트에 삽입 후 오름차순 정렬, 탐색*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct CircleLinkedList* link;
}CircleLinkedList;

CircleLinkedList* find_pre(CircleLinkedList* head, CircleLinkedList* tmp) {
	CircleLinkedList* pre = head->link;
	while (true) {
		if (pre->link == tmp)break;
		pre = pre->link;
	}
	return pre;
}

//오름차순으로
CircleLinkedList* insert(CircleLinkedList* head, int data) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));
	if (!p) {
		printf("메모리 공간이 부족합니다.\n");
		exit(1);
	}
	p->data = data;
	if (head == NULL) {
		head = p;
		p->link = p;
	}
	else {
		CircleLinkedList* tmp = head->link;
		while (true) {
			if (tmp->data > p->data) {
				if (tmp->link ==tmp && head == tmp) {
					p->link = head->link;
					tmp->link = p;
				}
				else if (tmp->link != tmp && head == tmp) {
					CircleLinkedList* pre = find_pre(head, tmp);
					p->link = tmp;
					pre->link = p;

				}
				else{
					CircleLinkedList* pre = find_pre(head, tmp);
					p->link = tmp;
					pre->link = p;
				}
				break;
			}
			else {
				if (tmp->link != tmp && head==tmp) {
					p->link = tmp->link;
					tmp->link = p;
					head = p;
					return head;
				}
				else if (tmp->link == tmp && head==tmp) {
					p->link = tmp;
					tmp->link = p;
					head = p;
					return head;
				}
			}
			tmp = tmp->link;
		}
	}
	return head;
}

void print_list(CircleLinkedList* head) {
	CircleLinkedList* tmp = head->link;
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return;
	}
	while (true) {
		printf("%d ", tmp->data);
		if (tmp == head)break;
		tmp = tmp->link;
	}
	printf("\n");
}

CircleLinkedList* search(CircleLinkedList* head, int data) {
	CircleLinkedList* tmp = head->link;
	while (true) {
		if (tmp->data == data) {
			return tmp;
		}
		tmp = tmp->link;
		if (tmp == head->link) {
			return NULL;
		}
	}
}

int getLength(CircleLinkedList* head) {
	CircleLinkedList* tmp = head->link;
	int cnt = 0;
	while (true) {
		cnt += 1;
		tmp = tmp->link;
		if (tmp == head->link)break;
	}
	return cnt;
}

int main(void) {
	CircleLinkedList* head = NULL;
	int input;
	int search_data;
	for (int i = 0; i < 5; i++) {
		printf("데이터: ");
		scanf_s("%d", &input);
		head = insert(head, input);
		print_list(head);
	}

	printf("리스트의 크기: %d\n", getLength(head));

	printf("탐색: ");
	scanf_s("%d", &search_data);
	CircleLinkedList* search_node = search(head, search_data);
	if (search_node != NULL) {
		printf("탐색 결과: %d\n", search_node->data);
	}
	else {
		printf("없는 데이터입니다.\n");
	}

	free(head);
	return 0;
}
