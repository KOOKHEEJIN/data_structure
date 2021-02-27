/*�ϳ��� ����Ʈ ¦/Ȧ�� ������*/
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int data;
	struct LinkedList* link;
}LinkedList;

LinkedList* insert(LinkedList* head, int number) {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = number;
	if (head == NULL) {
		p->link = NULL;
		head = p;
	}
	else {
		LinkedList* tmp = head;
		while (true) {
			if (tmp->link == NULL) {
				p->link = tmp->link;
				tmp->link = p;
				break;
			}
			tmp = tmp->link;
		}
	}
	return head;
}


void print_list(LinkedList* head) {
	for (LinkedList* tmp = head; tmp != NULL; tmp = tmp->link) {
		printf("%d-> ", tmp->data);
	}
	printf("NULL\n");
}


//���� ������ �򰥸�������
void split(LinkedList* head, LinkedList** alist, LinkedList** blist) {
	LinkedList* tmp = head;
	while (true) {
		if (tmp == NULL)break;

		if (tmp->data % 2 == 0) {
			*alist = insert(*alist, tmp->data);
		}
		else {
			*blist = insert(*blist, tmp->data);
		}
		tmp = tmp->link;
	}
}



int main(void) {
	LinkedList* head = NULL;
	LinkedList* alist = NULL;
	LinkedList* blist = NULL;
	

	for (int i = 1; i <= 5 ; i++) {
		head = insert(head, i);
		print_list(head);
	}
	
	split(head, &alist, &blist);
	printf("¦�� ����Ʈ: ");
	print_list(alist);
	printf("Ȧ�� ����Ʈ: ");
	print_list(blist);

	return 0;
}