/*연결리스트, 방정식*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int coef;		//계수
	int expon;		//차수
	struct LinkedList* link;
}LinkedList;

typedef struct {
	int size;
	LinkedList* head;
	LinkedList* tail;
}Header;

//create
LinkedList* create() {
	Header* header = (Header*)malloc(sizeof(Header));
	if (!header) {
		printf("메모리가 부족합니다\n");
		exit(1);
	}
	header->size = 0;
	header->head = NULL;
	header->tail = NULL;
	return header;
}

//insert
void insert_last(Header* header, int coef, int expon) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (p == NULL) {
		printf("메모리가 부족합니다\n");
		exit(1);
	}
	p->coef = coef;
	p->expon = expon;
	p->link = NULL;
	if (header->tail==NULL) {
		header->head = p;
		header->tail = p;
	}
	else {
		header->tail->link = p;
		header->tail = p;
	}
	header->size++;
}

//방정식 출력
void poly_print(Header* header) {
	LinkedList* tmp = header->head;
	while(true) {
		if (tmp == header->tail) {
			printf("%dx^%d\n",tmp->coef,tmp->expon);
			break;
		}
		else {
			printf("%dx^%d + ",tmp->coef, tmp->expon);
		}
		tmp = tmp->link;
	}
}

//방정식 덧셈
void poly_add(Header* header1, Header* header2, Header* result) {
	LinkedList* tmp1 = header1->head;
	LinkedList* tmp2 = header2->head;
	while (true) {
		if (tmp1 == NULL || tmp2 == NULL) break;
		if (tmp1->expon == tmp2->expon) {
			if (tmp1->coef + tmp2->coef != 0) {
				insert_last(result, tmp1->coef + tmp2->coef, tmp1->expon);
			}
			tmp1 = tmp1->link;
			tmp2 = tmp2->link;
		}
		else if (tmp1->expon > tmp2->expon) {
			insert_last(result, tmp1->coef, tmp1->expon);
			tmp1 = tmp1->link;
		}
		else if (tmp1->expon < tmp2->expon) {
			insert_last(result, tmp2->coef, tmp2->expon);
			tmp2 = tmp2->link;
		}
	}

	while (true) {
		if (tmp1 == NULL && tmp2 != NULL) {
			insert_last(result, tmp2->coef, tmp2->expon);
			tmp2 = tmp2->link;
		}
		else if (tmp2 == NULL && tmp1 != NULL) {
			insert_last(result, tmp1->coef, tmp1->expon);
			tmp1 = tmp1->link;
		}
		else if (tmp1 == NULL && tmp2 == NULL) {
			break;
		}
	}
}

int main(void) {
	Header* A, * B, * result;
	A = create();
	B = create();
	result = create();
	insert_last(A, 3, 12);
	insert_last(A, 2, 8);
	insert_last(A, 1, 0);
	printf("A(x) = ");
	poly_print(A);

	insert_last(B, 8, 12);
	insert_last(B, -2, 8);
	insert_last(B, 3, 1);
	printf("B(x) = ");
	poly_print(B);

	poly_add(A, B, result);
	printf("F(x) = ");
	poly_print(result);

	return 0;
}
