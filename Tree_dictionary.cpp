/*Ʈ��, ����, c++*/
#include <iostream>
#include <string>
using namespace std;

//��� Ŭ����
class NodeType {
	string word;	//�ܾ�
	string meaning;	//�ǹ�
	NodeType* left;
	NodeType* right;
public:
	NodeType(string word = "", string meaning = "") {
		this->word = word;
		this->meaning = meaning;
	}
	~NodeType(){
		delete left;
		delete right;
		if (!left && !right) {
			cout << "�޿�������";
		}
	}
	string getWord() { return word; }
	string getMeaning() { return meaning; }
	void setLeft(NodeType* left) { this->left = left; }
	void setRight(NodeType* right) { this->right = right; }
	NodeType* getLeft() { return left; }
	NodeType* getRight() { return right; }
};

//Ʈ�� Ŭ����
class TreeType{
protected:
	NodeType* root;
public:
	virtual ~TreeType() {
		if (!root)cout << "������";
	}
	void insertNode(NodeType** root, NodeType* node);	//����
	NodeType* searchWord(NodeType* root, string word);	//Ž��
	void print_tree_inorder(NodeType* root);			//print
};

void TreeType::insertNode(NodeType** root, NodeType* node) {
	if (*root == NULL) {
		*root = node;
		node->setLeft(NULL);
		node->setRight(NULL);
	}
	else {
		NodeType* tmp = *root;
		while (tmp) {
			if (node->getWord() < tmp->getWord()) {
				if (tmp->getLeft() == NULL) {
					tmp->setLeft(node);
					break;
				}
				tmp = tmp->getLeft();
			}
			else if (node->getWord() > tmp->getWord()) {
				if (tmp->getRight() == NULL) {
					tmp->setRight(node);
					break;
				}
				tmp = tmp->getRight();
			}
		}
	}
}

NodeType* TreeType::searchWord(NodeType* root, string word) {
	NodeType* tmp = root;
	while (tmp) {
		if (word == tmp->getWord())return tmp;
		else if (word < tmp->getWord()) {
			tmp = tmp->getLeft();
		}
		else {
			tmp = tmp->getRight();
		}
	}
	return NULL;
}

void TreeType::print_tree_inorder(NodeType* root) {
	if (root) {
		print_tree_inorder(root->getLeft());
		cout << root->getWord() << ", " << root->getMeaning() << endl;
		print_tree_inorder(root->getRight());
	}
}

class Dictionary :public TreeType {
public:
	~Dictionary() {
		cout << "�Ҹ��� ����" << endl;
		delete root;
		if (root == NULL)cout << "�Ҹ�!" << endl;
	}
	void Manage() {
		int input;
		cout << "�ܾ��忡 �� ���� ȯ���մϴ�!" << endl;
		cout << "���ϴ� �۾� ��ư�� Ŭ���ϼ���." << endl;
		cout << "[1] �ܾ� �߰�" << endl << "[2] �ܾ� Ž��" << endl << "[3] ��� �ܾ� ���" << endl;
		while (true) {
			cout << "��ȣ �Է�: ";
			cin >> input;
			if (input == 0)break;
			switch (input)
			{
			case 1: {
				AddData();
				break;
			}
			case 2: {
				searchData();
				break;
			}
			case 3: {
				printData();
				break;
			}
			default:
				break;
			}
		}
	}
	void AddData() {
		string word;
		string meaning;
		cout << "�ܾ� �Է�: ";
		cin >> word;
		cout << "�ǹ� �Է�: ";
		cin >> meaning;
		NodeType* node = new NodeType(word, meaning);
		insertNode(&root, node);
	}
	void searchData() {
		string word;
		cout << "Ž���Ϸ��� �ܾ �Է��ϼ���: ";
		cin >> word;
		if (!searchWord(root, word)) {
			cout << "���� �������Դϴ�." << endl;
		}
		else {
			cout << searchWord(root, word)->getWord() << ":" << searchWord(root, word)->getMeaning() << endl;
		}
	}
	void printData() {
		print_tree_inorder(root);
	}
};

int main() {
	Dictionary dic;
	dic.Manage();
}