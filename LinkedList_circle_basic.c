/*원형 연결리스트 기본*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int data;
	struct CircleLinkedList* link;
}CircleLinkedList;

//연결리스트 맨 앞에 삽입하는 함수
CircleLinkedList* insert_first(CircleLinkedList* head, int number) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));	//동적 생성
	if (head == NULL) {		//연결리스트가 비어있다면
		p->data = number;
		head = p;			//head포인터가 가리키는 것은 p
		p->link = p;		//p는 자기 자신 가리킴
	}
	else {
		p->data = number;
		p->link = head->link;
		head->link = p;
		
	}
	return head;
}

//연결리스트 마지막에 삽입하는 함수
CircleLinkedList* insert_last(CircleLinkedList* head, int number) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));	//동적 생성
	p->data = number;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
		head = p;
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
		printf("%d-> ", tmp->data);
		if (tmp == head) {
			printf("NULL\n");
			break;
		}
		tmp = tmp->link;

	}
}

int main(void) {
	CircleLinkedList* head = NULL;
	int input;
	for (int i = 0; i < 5; i++) {
		printf("데이터: ");
		scanf_s("%d", &input);	//데이터 입력 받기
		head = insert_last(head, input);
		print_list(head);
	}
	
	return 0;
}