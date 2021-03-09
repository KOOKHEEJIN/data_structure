#include <stdio.h>]
#include <stdbool.h>

typedef int element;
typedef struct {
	element data;
	struct LinkedListNode* link;
}LinkedListNode;


LinkedListNode* insert_first(LinkedListNode* head, element item) {
	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	p->link = head;
	p->data = item;
	head = p;
	return head;
}

LinkedListNode* insert(LinkedListNode* head, LinkedListNode* pre, element item) {
	if (head == NULL) {
		head = insert_first(head, item);
	}
	else {
		LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		p->link = pre->link;
		p->data = item;
		pre->link = p;
	}
	return head;
}

LinkedListNode* delete_first(LinkedListNode* head) {
	LinkedListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

LinkedListNode* delete(LinkedListNode* head, LinkedListNode* pre) {
	LinkedListNode* removed;
	if (head == NULL) return NULL;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(LinkedListNode* head) {
	for (LinkedListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
		
	}
	printf("NULL\n");
}

int main(void) {
	LinkedListNode* head = NULL;
	LinkedListNode* tmp = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert(head, tmp, i);
		print_list(head);
		LinkedListNode* p = head;
		while (true) {
			if (p->link == NULL) {
				tmp = p;
				break;
			}
			p = p->link;
		}
	}
	

	return 0;

}
