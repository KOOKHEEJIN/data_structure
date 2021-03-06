/*중위순회 스레드 이진트리*/

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;


TreeNode* find_successor(TreeNode* root) {
	TreeNode* p = root->right;
	if (!p || root->is_thread == TRUE) {
		return p;
	}
	while (p->left) {
		p = p->left;
	}
	return p;
}


void thread_inorder(TreeNode* root) {
	while (root->left) {
		root = root->left;
	}
	do {
		printf("%d-> ", root->data);
		root = find_successor(root);
		
	} while (root);
	if (!root)free(root);
}


int main(void) {
	TreeNode n1 = { 0,NULL,NULL,1 };
	TreeNode n2 = { 3,NULL,NULL,1 };
	TreeNode n3 = { 5,&n1,NULL,1 };
	TreeNode n4 = { 4,NULL,&n2,0 };
	TreeNode n5 = { 11,&n4,&n3,0 };
	TreeNode n6 = { 7,NULL,NULL,1 };
	TreeNode n7 = { 6,&n5,&n6,1 };
	TreeNode n8 = { 19,NULL,NULL,1 };
	TreeNode n9 = { 15,&n8,NULL,1 };
	TreeNode n10 = { 12,&n9,NULL,0 };
	TreeNode n11 = { 27,NULL,NULL,1 };
	TreeNode n12 = { 8,&n11,&n10,0 };
	TreeNode n13 = { 1,&n7,&n12,0 };
	TreeNode* root = &n13;

	n1.right = &n3;
	n2.right = &n5;
	n3.right = &n7;
	n6.right = &n13;
	n11.right = &n12;
	n8.right = &n9;
	n9.right = &n10;

	thread_inorder(root);
	
	//add
	//free(root);
	
	return 0;
}
