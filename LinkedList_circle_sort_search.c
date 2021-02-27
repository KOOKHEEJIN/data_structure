/*���Ḯ��Ʈ�� ���� �� �������� ����, Ž��*/
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

//������������
CircleLinkedList* insert(CircleLinkedList* head, int data) {
	CircleLinkedList* p = (CircleLinkedList*)malloc(sizeof(CircleLinkedList));
	if (!p) {
		printf("�޸� ������ �����մϴ�.\n");
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
		printf("������: ");
		scanf_s("%d", &input);
		head = insert(head, input);
		print_list(head);
	}

	printf("����Ʈ�� ũ��: %d\n", getLength(head));

	printf("Ž��: ");
	scanf_s("%d", &search_data);
	CircleLinkedList* search_node = search(head, search_data);
	if (search_node != NULL) {
		printf("Ž�� ���: %d\n", search_node->data);
	}
	else {
		printf("���� �������Դϴ�.\n");
	}

	free(head);
	return 0;
}