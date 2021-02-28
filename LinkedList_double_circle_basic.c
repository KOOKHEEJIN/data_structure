/*���� ���� ���Ḯ��Ʈ �⺻
���� Ƚ���� �Է¹޾� �׸�ŭ ����Ʈ ������ ���
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct DoubleLinkedList {
	int data;
	struct DoubleLinkedList* llink;
	struct DoubleLinkedList* rlink;
}DoubleLinkedList;

//�ʱ�ȭ
DoubleLinkedList* init(DoubleLinkedList* head) {
	head->llink = head;
	head->rlink = head;
	return head;
}

//ó���� ����
DoubleLinkedList* insert_first(DoubleLinkedList* head, int data) {
	DoubleLinkedList* p = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	DoubleLinkedList* tmp = head;	//�ӽ� ���
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

//�������� ����
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

//����Ʈ ���
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

//����
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
		printf("������: ");
		scanf_s("%d", &input);
		head = insert_first(head, input);
		print_list(head);
	}

	printf("\n��� �����Ͻðڽ��ϱ�? ");
	scanf_s("%d", &input);		//��������Ʈ ���� Ƚ��
	print_list_cnt(head, input);	//�����ϴ� �������Ḯ��Ʈ ���

	free(head);
	return 0;
}