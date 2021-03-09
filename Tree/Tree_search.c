/*이진탐색트리 삽입, 삭제, 탐색*/

#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;

}TreeNode;

//초기화
TreeNode* init(int key) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = key;
	p->right = NULL;
	p->left = NULL;
	return p;
}

//insert
void insert(TreeNode* root, int key) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = key;
	p->left = NULL;
	p->right = NULL;
	TreeNode* tmp = root;
	while (tmp) {
		if (p->key < tmp->key) {
			if (!tmp->left) {
				tmp->left = p;
				break;
			}
			tmp = tmp->left;
		}
		else if (p->key > tmp->key) {
			if (!tmp->right) {
				tmp->right = p;
				break;
			}
			tmp = tmp->right;
		}
		else return;

	}
}

//search
TreeNode* search(TreeNode* root, int key) {
	while (root) {
		if (key == root->key) {
			return root;
		}
		else if (key < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return NULL;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left) {
		current = current->left;
	}
	return current;
}

//remove
TreeNode* remove_node(TreeNode* root, int key) {
	if (!root)return root;
	if (key < root->key) {
		root->left = remove_node(root->left, key);
	}
	else if (key > root->key) {
		root->right = remove_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}
		TreeNode* tmp = min_value_node(root->right);
		root->key = tmp->key;
		root->right = remove_node(root->right, tmp->key);	//why?
	}
	return root;
}

//중위순회로 출력
void print_tree_inorder(TreeNode* root) {
	if (root) {
		print_tree_inorder(root->left);
		printf("%d-> ", root->key);
		print_tree_inorder(root->right);
	}
}

int main(void) {
	TreeNode* n1 = init(50);
	TreeNode* n2 = init(25);
	TreeNode* n3 = init(75);
	n1->left = n2;
	n1->right = n3;
	TreeNode* root = n1;
	TreeNode* search_node;
	insert(root, 24);
	insert(root, 36);
	insert(root, 34);
	insert(root, 21);
	insert(root, 47);
	insert(root, 66);
	print_tree_inorder(root);
	printf("\n");
	
	search_node = search(root, 24);
	if (!search_node)printf("없는 데이터입니다.\n");
	else printf("[%d] ", search_node->key);
	printf("\n");
	
	remove_node(root, 21);
	remove_node(root, 25);
	print_tree_inorder(root);

	free(root);
	return 0;
}
