/*이진트리 순회 반복문-스택을 이용하여 할 수 있다.*/

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//스택
typedef struct StackNode{
	struct TreeNode** node;
	struct StackNode* link;
}StackNode;

//push
void push(TreeNode* root, StackNode** top) {
	StackNode* stack_node = (StackNode*)malloc(sizeof(StackNode));
	stack_node->node = root;
	stack_node->link = *top;
	*top = stack_node;
}

//pop
TreeNode* pop(StackNode** top) {
	if (*top == NULL)return NULL;
	StackNode* tmp = *top;
	TreeNode* p = (*top)->node;
	*top = tmp->link;
	free(tmp);
	return p;
}

//중위 순회
void inorder(StackNode** top, TreeNode* root) {
	while (true) {
		for (; root != NULL; root = root->left) {
			push(root, top);
		}
		root = pop(top);
		if (root == NULL) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

//전위 순회
void preorder(StackNode** top, TreeNode* root) {
	while (true) {
		for (; root != NULL; root = root->left) {
			printf("[%d] ", root->data);
			push(root, top);
		}
		root = pop(top);
		if (!root)break;
		root = root->right;
	}
}

/*후위순회 반복법 모르겠음, 나중에*/
void postorder(StackNode** top, TreeNode* root) {
	if (root) {
		postorder(top, root->left);
		postorder(top, root->right);
		printf("[%d] ", root->data);
	}
}

int main(void) {
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3,&n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode* root = &n6;

	StackNode* top = NULL;
	printf("inorder: ");
	inorder(&top, root);
	printf("\n");
	printf("preorder: ");
	preorder(&top, root);
	printf("\n");
	printf("postorder: ");
	postorder(&top, root);
	printf("\n");

	return 0;
}
