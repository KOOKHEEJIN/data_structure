/*우선순위 큐 정렬*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 8

//힙
typedef struct HeapNode{
	int heap[MAX_SIZE];
	int heap_size;
}HeapNode;

//create
HeapNode* create() {
	HeapNode* h = (HeapNode*)malloc(sizeof(HeapNode));
	h->heap_size = 0;
	return h;
}

//insert
void insert(HeapNode* h, int key){
	h->heap_size += 1;	//힙 사이즈 증가
	int index = h->heap_size;
	while (index != 1) {		//index가 1이 아닐 때,
		if (key <= h->heap[index / 2])break;
		if (key > h->heap[index / 2]) {
			h->heap[index] = h->heap[index / 2];
			index /= 2;
		}
	}
	h->heap[index] = key;
}

//delete
int delete(HeapNode* h) {
	int item = h->heap[1];
	int tmp = h->heap[h->heap_size];
	h->heap_size -= 1;
	int parent = 1;
	int child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) {
			child += 1;
		}
		if (tmp >= h->heap[child])break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}

//print
void print_arry(HeapNode* h) {
	for (int i = 1; i < MAX_SIZE; i++) {
		printf("%d ", h->heap[i]);
	}
}

//sort
void heap_sort(int* heap[], HeapNode* h) {
	for (int i = 1; i < MAX_SIZE; i++) {
		int data = delete(h);
		heap[MAX_SIZE - i] = data;		//힙에 삭제된 데이터 삽입
	}
}

int main(void) {
	HeapNode* heap = create();
	int input;
	for (int i = 1; i < MAX_SIZE; i++) {
		printf("\n입력: ");
		scanf_s("%d", &input);
		insert(heap, input);
		print_arry(heap);	//쓰레기값 출력됨. 
	}
	printf("\n");
	heap_sort(heap->heap, heap);
	for (int i = 1; i < MAX_SIZE; i++) {
		printf("%d ", heap->heap[i]);
	}

	return 0;
}