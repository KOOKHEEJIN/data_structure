/*���Ḯ��Ʈ ���� ���*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//���Ḯ��Ʈ ����ü
typedef struct LinkedList {
	int data;	//������
	struct LinkedList* link;	//��ũ
}LinkedList;

//���� ����ü
typedef struct {
	struct LinkedStackType* top;
}LinkedStackType;

//push
LinkedStackType* push(LinkedStackType* top, int data) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (!p)exit(1);
	p->data = data;
	if (top == NULL) {	//top�����Ͱ� ����Ű�� ���� �ƹ��͵� ���ٸ�,
		top = p;
		p->link = NULL;
		return top;
	}
	p->link = top;	//p�� ����Ű�� top�� ����Ű�� ��
	top = p;		//top�� p�� ����Ŵ
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
		printf("������: ");
		scanf_s("%d", &input);		//������ �Է�
		top=push(top, input);
		print_list(top);
	}

	printf("\n�޸𸮸� �����մϴ�.\n");
	for (int i = 0; i < 5; i++) {
		pop(&top);
		print_list(top);
	}

	return 0;
}