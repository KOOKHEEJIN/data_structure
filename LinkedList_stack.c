/*연결리스트 스택 사용*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//연결리스트 구조체
typedef struct LinkedList {
	int data;	//데이터
	struct LinkedList* link;	//링크
}LinkedList;

//스택 구조체
typedef struct {
	struct LinkedStackType* top;
}LinkedStackType;

//push
LinkedStackType* push(LinkedStackType* top, int data) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (!p)exit(1);
	p->data = data;
	if (top == NULL) {	//top포인터가 가리키는 것이 아무것도 없다면,
		top = p;
		p->link = NULL;
		return top;
	}
	p->link = top;	//p가 가리키는 top이 가리키는 것
	top = p;		//top은 p를 가리킴
	return top;
}

//pop
void pop(LinkedStackType** top) {
	if (*top == NULL) {
		printf("stack is empty!\n");
		exit(1);
	}
	LinkedList* tmp = *top;
	*top = tmp->link;
	free(tmp);
}

//list print
void print_list(LinkedStackType* top) {
	LinkedList* tmp = top;
	while (true) {
		if (tmp == NULL) {
			printf("NULL\n");
			break;
		}
		printf("%d-> ", tmp->data);
		tmp = tmp->link;
	}
}

int main(void) {
	LinkedStackType* top = NULL;
	int input;
	for (int i = 0; i < 5; i++) {
		printf("데이터: ");
		scanf_s("%d", &input);		//데이터 입력
		top=push(top, input);
		print_list(top);
	}

	printf("\n메모리를 해제합니다.\n");
	for (int i = 0; i < 5; i++) {
		pop(&top);
		print_list(top);
	}

	return 0;
}