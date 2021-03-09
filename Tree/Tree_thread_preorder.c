/*전위순회 스레드 이진트리, 미완*/

#define TRUE 1
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode* find_successor(TreeNode* root) {
	TreeNode* p = root->right;
	if (!p || p->is_thread == TRUE) {
		return p;
	}
	while (p->left) {
		printf("%d-> ", p->data);
		p = p->left;
	}
	return p;
}

void preorder(TreeNode* root) {
	while (true) {
		printf("%d-> ", root->data);
		if (root->left)root = root->left;
		else break;
	}
	while (true) {
		root = find_successor(root);
		if (!root)break;
		printf("%d-> ", root->data);
	}
}


int main(void) {
	TreeNode n0 = { 0,NULL,NULL,1 };
	TreeNode n3 = { 3,NULL,NULL,1 };
	TreeNode n5 = { 5,&n0,NULL,0 };
	TreeNode n4 = { 4,NULL,&n3,0 };
	TreeNode n11 = { 11,&n4,&n5,0 };
	TreeNode n7 = { 7,NULL,NULL,1 };
	TreeNode n6 = { 6,&n11,&n7,0 };
	TreeNode n19 = { 19,NULL,NULL,0 };
	TreeNode n15 = { 15,&n19,NULL,0 };
	TreeNode n12 = { 12,&n15,NULL,0 };
	TreeNode n27 = { 27,NULL,NULL,1 };
	TreeNode n8 = { 8,&n27,&n12,0 };
	TreeNode n1 = { 1,&n6,&n8,0 };
	TreeNode* root = &n1;

	n0.right = &n7;
	n3.right = &n5;
	n7.right = &n8;
	n27.right = &n12;

	preorder(root);
	
	//add
	//free(root); 

	return 0;
}
