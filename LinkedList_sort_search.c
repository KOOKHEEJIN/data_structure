/*단순 연결리스트-내림차순 정렬, 탐색*/
/*성적 프로그램*/

#pragma warning(disable:6031)	//scanf사용 시 오류메시지 안뜨게 하기 위한 것
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

/*현재 노드의 이전 노드를 탐색하는 함수*/
LinkedList* find_pre(LinkedList* head, LinkedList* node) {
	LinkedList* pre = head;
	for (pre; pre != NULL; pre = pre->link) {
		if (pre->link == node) {
			break;
		}
	}
	return pre;
}

/*내림차순으로 노드를 삽입하는 함수*/
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

/*노드를 탐색하는 함수*/
LinkedList* search(LinkedList* head, element data) {
	LinkedList* tmp = head;
	while (true) {
		if (tmp == NULL) break;					

		if (!strcmp(tmp->name, data)) {   //str1 == str2 인 경우에는 0을 반환 합니다.
			break;
		}
		tmp = tmp->link;
	}
	return tmp;		//탐색 실패시 tmp==NULL, 성공시 tmp==해당 노드
}

/*연결리스트의 노드를 순차적으로 출력하는 함수*/
void print_list(LinkedList* head) {
	int i = 1;
	printf("==========순위 발표===========\n");
	for (LinkedList* node = head; node != NULL; node = node->link) {
		printf("%d등: %s, %d점\n", i, node->name, node->number);
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
		printf("(%d) 이름, 점수 입력: ", i);
		scanf("%s %d", input_name, &input_num);
		if (input_num==999) {
			printf("입력을 종료합니다.\n\n");
			break;
		}
		head = insert(head, input_name, input_num);
		i += 1;
	}

	print_list(head);

	char c = getchar();		//입력 버퍼를 비워주기 위한 코드
	printf("%c", c);		//입력 버퍼에는 '\n'이 남아있었음

	
	printf("자료명 입력: ");
	scanf("%s", search_name);
	LinkedList* search_node = search(head, search_name);

	if (search_node != NULL) {
		printf("이름: %s, 점수: %d\n", search_node->name, search_node->number);
	}
	else {
		printf("존재하지 않는 데이터입니다.\n");
		
	}
	
	return 0;
}