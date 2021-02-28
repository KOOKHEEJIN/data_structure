/*���� ���Ḯ��Ʈ �⺻*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int data;
	struct CircleLinkedList* link;
}CircleLinkedList;

//���Ḯ��Ʈ �� �տ� �����ϴ� �Լ�
CircleLinkedList* insert_first(CircleLinkedList* head, int number) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));	//���� ����
	if (head == NULL) {		//���Ḯ��Ʈ�� ����ִٸ�
		p->data = number;
		head = p;			//head�����Ͱ� ����Ű�� ���� p
		p->link = p;		//p�� �ڱ� �ڽ� ����Ŵ
	}
	else {
		p->data = number;
		p->link = head->link;
		head->link = p;
		
	}
	return head;
}

//���Ḯ��Ʈ �������� �����ϴ� �Լ�
CircleLinkedList* insert_last(CircleLinkedList* head, int number) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));	//���� ����
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
		printf("������: ");
		scanf_s("%d", &input);	//������ �Է� �ޱ�
		head = insert_last(head, input);
		print_list(head);
	}
	
	return 0;
}