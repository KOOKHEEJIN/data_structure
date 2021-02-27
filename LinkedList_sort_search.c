/*�ܼ� ���Ḯ��Ʈ-�������� ����, Ž��*/
/*���� ���α׷�*/

#pragma warning(disable:6031)	//scanf��� �� �����޽��� �ȶ߰� �ϱ� ���� ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char element[100];
typedef struct {
	element name;
	int number;
	struct LinkedList* link;
}LinkedList;

/*���� ����� ���� ��带 Ž���ϴ� �Լ�*/
LinkedList* find_pre(LinkedList* head, LinkedList* node) {
	LinkedList* pre = head;
	for (pre; pre != NULL; pre = pre->link) {
		if (pre->link == node) {
			break;
		}
	}
	return pre;
}

/*������������ ��带 �����ϴ� �Լ�*/
LinkedList* insert(LinkedList* head, element data, int data_num) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	strcpy(p->name, data);
	p->number = data_num;
	if (head == NULL) {
		p->link = head;
		head = p;
	}
	else {
		LinkedList* tmp = head;
		while (true) {
			if (p->number > tmp->number) {
				if (tmp == head) {
					p->link = head;
					head = p;
				}
				else {
					LinkedList* pre;
					pre = find_pre(head, tmp);
					pre->link = p;
					p->link = tmp;					
				}
				break;
			}
			else {
				if (tmp->link == NULL) {
					p->link = tmp->link;
					tmp->link = p;
					break;
				}
				tmp = tmp->link;
			}
		}
	}
	return head;
}

/*��带 Ž���ϴ� �Լ�*/
LinkedList* search(LinkedList* head, element data) {
	LinkedList* tmp = head;
	while (true) {
		if (tmp == NULL) break;					

		if (!strcmp(tmp->name, data)) {   //str1 == str2 �� ��쿡�� 0�� ��ȯ �մϴ�.
			break;
		}
		tmp = tmp->link;
	}
	return tmp;		//Ž�� ���н� tmp==NULL, ������ tmp==�ش� ���
}

/*���Ḯ��Ʈ�� ��带 ���������� ����ϴ� �Լ�*/
void print_list(LinkedList* head) {
	int i = 1;
	printf("==========���� ��ǥ===========\n");
	for (LinkedList* node = head; node != NULL; node = node->link) {
		printf("%d��: %s, %d��\n", i, node->name, node->number);
		i++;
	}
}

int main(void) {
	LinkedList* head = NULL;
	element input_name = "";
	element search_name;
	int input_num = -1;
	int i = 1;

	while (true) {
		printf("(%d) �̸�, ���� �Է�: ", i);
		scanf("%s %d", input_name, &input_num);
		if (input_num==999) {
			printf("�Է��� �����մϴ�.\n\n");
			break;
		}
		head = insert(head, input_name, input_num);
		i += 1;
	}

	print_list(head);

	char c = getchar();		//�Է� ���۸� ����ֱ� ���� �ڵ�
	printf("%c", c);		//�Է� ���ۿ��� '\n'�� �����־���

	
	printf("�ڷ�� �Է�: ");
	scanf("%s", search_name);
	LinkedList* search_node = search(head, search_name);

	if (search_node != NULL) {
		printf("�̸�: %s, ����: %d\n", search_node->name, search_node->number);
	}
	else {
		printf("�������� �ʴ� �������Դϴ�.\n");
		
	}
	
	return 0;
}