#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

};

struct List
{

	Node* head = nullptr;
	Node* tail = nullptr;

	void insertAtStart(int data) {
		Node* temp = new Node(data, nullptr);
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}

	void insertAtEnd(int data) {
		Node* temp = new Node(data, nullptr);
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void popTop() {
		if (head->next == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* toDelete = head;
			head = head->next;
			delete toDelete;
		}
		
	}

	void popBack() {
		Node* curr = head;
		Node* previous = head;
		while (curr->next != nullptr) {
			previous = curr;
			curr = curr->next;
		}
		tail = previous;
		previous->next = nullptr;
		delete curr;
	}

	void print() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

};
