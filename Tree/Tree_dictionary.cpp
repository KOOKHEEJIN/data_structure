/*트리, 사전, c++*/
#include <iostream>
#include <string>
using namespace std;

//노드 클래스
class NodeType {
	string word;	//단어
	string meaning;	//의미
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
			cout << "왼오없어짐";
		}
	}
	string getWord() { return word; }
	string getMeaning() { return meaning; }
	void setLeft(NodeType* left) { this->left = left; }
	void setRight(NodeType* right) { this->right = right; }
	NodeType* getLeft() { return left; }
	NodeType* getRight() { return right; }
};

//트리 클래스
class TreeType{
protected:
	NodeType* root;
public:
	virtual ~TreeType() {
		if (!root)cout << "없어짐";
	}
	void insertNode(NodeType** root, NodeType* node);	//삽입
	NodeType* searchWord(NodeType* root, string word);	//탐색
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
		cout << "소멸자 실행" << endl;
		delete root;
		if (root == NULL)cout << "소멸!" << endl;
	}
	void Manage() {
		int input;
		cout << "단어장에 온 것을 환영합니다!" << endl;
		cout << "원하는 작업 버튼을 클릭하세요." << endl;
		cout << "[1] 단어 추가" << endl << "[2] 단어 탐색" << endl << "[3] 모든 단어 출력" << endl;
		while (true) {
			cout << "번호 입력: ";
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
		cout << "단어 입력: ";
		cin >> word;
		cout << "의미 입력: ";
		cin >> meaning;
		NodeType* node = new NodeType(word, meaning);
		insertNode(&root, node);
	}
	void searchData() {
		string word;
		cout << "탐색하려는 단어를 입력하세요: ";
		cin >> word;
		if (!searchWord(root, word)) {
			cout << "없는 데이터입니다." << endl;
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
