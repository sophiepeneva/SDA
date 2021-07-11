/*
#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int data, Node* left, Node* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

struct Tree
{

	Node* root = nullptr;

	void insert(int data) {
		if (root == nullptr) {
			root = new Node(data, nullptr, nullptr);
		}
		else {
			insert(data, root);
		}
	}

	Node* insert(int data, Node* curr) {
		if (curr == nullptr) {
			return new Node(data, nullptr, nullptr);
		}
		if (curr->data > data) {
			curr->left = insert(data, curr->left);
		}
		if (curr->data < data) {
			curr->right = insert(data, curr->right);
		}
		return curr;
	}

	int getMin() {
		if (root == nullptr)return -1;
		return getMin(root)->data;
	}

	Node* getMin(Node* curr) {
		if (curr->left == nullptr)return curr;
		return getMin(curr->left);
	}

	int getMax() {
		if (root == nullptr)return -1;
		return getMax(root)->data;
	}

	Node* getMax(Node* curr) {
		if (curr->right == nullptr)return curr;
		return getMax(curr->right);
	}

	bool find(int data) {
		return find(data, root) != nullptr;
	}

	Node* find(int data, Node* curr) {
		if (curr == nullptr) {
			return curr;
		}
		if (curr->data == data)return curr;
		if (curr->data > data) {
			return find(data, curr->left);
		}
		if (curr->data < data) {
			return find(data, curr->right);
		}
	}

	void deleteKey(int data) {
		deleteKey(data, root);
	}

	Node* deleteKey(int data, Node* curr) {
		if (curr == nullptr) {
			return curr;
		}
		if (curr->data == data) {
			if (curr->left == nullptr) {
				Node* temp = curr->right;
				free(curr);
				return temp;
			}
			else if (curr->right == nullptr) {
				Node* temp = curr->left;
				free(curr);
				return temp;
			}
			Node* temp = getMin(curr->right);
			curr->data = temp->data;
			curr->right = deleteKey(temp->data, curr->right);
		}
		if (curr->data > data) {
			curr->left = deleteKey(data, curr->left);
		}
		if (curr->data < data) {
			curr->right = deleteKey(data, curr->right);
		}

	}

	void printPreorder() {
		printPreorder(root);
	}

	void printInorder() {
		printInorder(root);
	}

	void printPostorder() {
		printPostorder(root);
	}

	void printPreorder(Node* curr) {
		if (curr == nullptr)return;
		cout << curr->data << " ";
		printInorder(curr->left);
		printInorder(curr->right);
	}

	void printInorder(Node* curr) {
		if (curr == nullptr)return;
		printInorder(curr->left);
		cout << curr->data<<" ";
		printInorder(curr->right);
	}

	void printPostorder(Node* curr) {
		if (curr == nullptr)return;
		printInorder(curr->left);
		printInorder(curr->right);
		cout << curr->data << " ";
	}
};


int main() {

	Tree tree;
	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.printPreorder();
	cout << endl;
	tree.printInorder();
	cout << endl;
	tree.printPostorder();
	cout << endl;
	cout << tree.getMin() << endl;
	cout << tree.getMax() << endl;
	for (int i = 0;i < 7;i++) {
		cout << i << " :" << tree.find(i) << endl;
	}
	system("pause");
}
*/