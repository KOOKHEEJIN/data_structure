/*단순연결리스트-리스트 2개 병합 및 오름차순 정렬*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
	element data;
	struct LinkedList* link;
}LinkedList;

//앞 노드 찾기
LinkedList* find_pre(LinkedList* head, LinkedList* node) {
	LinkedList* pre = head;
	while (true) {
		if (pre->link == node) {
			break;
		}
		pre = pre->link;
	}
	return pre;
}

//삽입
LinkedList* insert(LinkedList* head, element number) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (!p) {
		printf("메모리 공간이 부족합니다.\n");
		exit(1);
	}
	p->data = number;
	if (head == NULL) {
		p->data = number;
		p->link = head;
		head = p;
	}
	else {
		LinkedList* tmp = head;
		while (true) {
			if (tmp->data >= p->data) {
				if (tmp == head) {
					p->link = tmp;
					head = p;
					break;
				}
				else {
					LinkedList* pre;
					pre = find_pre(head, tmp);
					p->link = tmp;
					pre->link = p;
					break;
				}
			}
			else if (tmp->link == NULL) {
				p->link = tmp->link;
				tmp->link = p;
				break;
			}
			tmp = tmp->link;
			
		}
	}
	return head;
}

//연결리스트 노드를 오름차순으로 병합
LinkedList* list_concat(LinkedList* head1, LinkedList* head2) {
	LinkedList* tmp2 = head2;
	for (LinkedList* tmp1 = head1; tmp1 != NULL; tmp1 = tmp1->link) {
		while (true) {
			if (tmp1->data >= tmp2->data) {
				LinkedList** next_tmp2 = tmp2->link;
				if (tmp1 == head1) {
					tmp2->link = tmp1;
					head1 = tmp2;
				}
				else if (tmp2->link == NULL) {
					LinkedList* pre;
					pre = find_pre(head1, tmp1);
					tmp2->link = tmp1;
					pre->link = tmp2;
					return head1;
				}
				else {
					LinkedList* pre;
					pre = find_pre(head1, tmp1);
					tmp2->link = tmp1;
					pre->link = tmp2;
				}
				tmp2 = next_tmp2;
			}
			else {
				if (tmp1->link == NULL) {
					tmp1->link = tmp2;
					return head1;
				}
				break;
			}
		}
	}
	return head1;
}

LinkedList* print_list(LinkedList* head) {
	for (LinkedList* p = head; p != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedList* head1 = NULL;
	LinkedList* head2 = NULL;
	element input1;
	element input2;
	srand((unsigned int)time(NULL));

	
	printf("=======List1=======\n");
	for (int i = 0; i < 5; i++) {
		printf("데이터 입력: ");
		input1 = rand() % 100;
		printf("%d\n", input1);
		head1 = insert(head1, input1);
	}
	print_list(head1);
	printf("=======List2=======\n");
	for (int i = 0; i < 5; i++) {
		printf("데이터 입력: ");
		input2 = rand() % 100;
		printf("%d\n", input2);
		head2 = insert(head2, input2);
	}
	print_list(head2);
	printf("\n======Concat======\n");
	head1 = list_concat(head1, head2);
	print_list(head1);
	
	return 0;
}
