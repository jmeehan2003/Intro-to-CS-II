#include <iostream>
#include "Queue.hpp"
using std::cout;
using std::endl;


int Queue::getFront() {
	if (!isEmpty()) 
		return head->val;
	else
		cout << "The list is empty!" << endl << endl;
}

void Queue::removeFront() {
	if (!isEmpty()) {
		// check if there is only one element in the list
		if (head->next == head) {
			QueueNode* temp = head;
			head = nullptr;
			delete temp;	
		}
		else {
		QueueNode* temp = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete temp;
		}
	}
	else
		cout << "Nothing was removed because the list is already empty." << endl << endl;
}

void Queue::addBack(int val) {
	// if list is empty
	if (head == nullptr) {
		QueueNode* newNode = new QueueNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		newNode->val = val;
		head = newNode;
	}
	else {
		QueueNode* newNode = new QueueNode;
		newNode->val = val;
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}
}

bool Queue::isEmpty() {
	if (head == nullptr)
		return true;
	else
		return false;
}

void Queue::printQueue() {
	if (!isEmpty()) {
		cout << "Your queue is: ";
		QueueNode* temp = head;
		do {
			cout << temp->val << " ";
			temp = temp->next;
		} while (temp != head);	
	}
	else
		cout << "The list is empty!";
	
	cout << endl << endl;
}

Queue::~Queue() {
	// if the list is empty, just delete the Queue object	
	while (!isEmpty()) {
		// check if there is only one element in the list
		if (head->next == head) {
			QueueNode* temp = head;
			head = nullptr;
			delete temp;	
		}
		else {
		QueueNode* temp = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete temp;
		}
	}
}
