/*원형 이중 연결리스트 기본
루프 횟수를 입력받아 그만큼 리스트 데이터 출력
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct DoubleLinkedList {
	int data;
	struct DoubleLinkedList* llink;
	struct DoubleLinkedList* rlink;
}DoubleLinkedList;

//초기화
DoubleLinkedList* init(DoubleLinkedList* head) {
	head->llink = head;
	head->rlink = head;
	return head;
}

//처음에 삽입
DoubleLinkedList* insert_first(DoubleLinkedList* head, int data) {
	DoubleLinkedList* p = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	DoubleLinkedList* tmp = head;	//임시 노드
	if (!p) exit(1);
	p->data = data;
	if (tmp->rlink == head) {
		p->llink = head;
		p->rlink = head;
		head->rlink = p;
		head->llink = p;
		return head;
	}
	while (true) {
		if (tmp->llink == head) {
			p->rlink = tmp;
			p->llink = tmp->llink;
			tmp->llink->rlink = p;
			tmp->llink = p;
			break;
		}
		tmp = tmp->rlink;
	}
	return head;
}

//마지막에 삽입
DoubleLinkedList* insert_last(DoubleLinkedList* head, int data) {
	DoubleLinkedList* p = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	DoubleLinkedList* tmp = head;
	if (!p) exit(1);
	p->data = data;
	while (true) {
		if (tmp->rlink == head) {
			p->rlink = head;
			p->llink = tmp;
			tmp->rlink = p;
			tmp->llink->llink = p;
			break;
		}
		tmp = tmp->rlink;
	}
	return head;
}

//리스트 출력
void print_list(DoubleLinkedList* head) {
	DoubleLinkedList* tmp = head->rlink;
	while (true) {
		printf(" <-%d-> ", tmp->data);
		tmp = tmp->rlink;
		if (tmp == head) {
			printf("\n");
			break;
		}
	}
}

//루프
void print_list_cnt(DoubleLinkedList* head, int number) {
	DoubleLinkedList* tmp = head->rlink;
	int cnt = 0;
	while (cnt != number) {
		printf("<-%d->", tmp->data);
		cnt++;
		tmp = tmp->rlink;
		if (tmp == head) {
			tmp = tmp->rlink;
		}
	}
}


int main(void) {
	DoubleLinkedList* head = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	int input;
	head = init(head);

	for (int i = 0; i < 5; i++) {
		printf("데이터: ");
		scanf_s("%d", &input);
		head = insert_first(head, input);
		print_list(head);
	}

	printf("\n몇번 루프하시겠습니까? ");
	scanf_s("%d", &input);		//원형리스트 루프 횟수
	print_list_cnt(head, input);	//루프하는 원형연결리스트 출력

	free(head);
	return 0;
}