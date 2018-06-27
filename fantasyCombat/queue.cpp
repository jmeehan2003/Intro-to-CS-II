#include <iostream>
#include "queue.hpp"
using std::cout;
using std::endl;


class Character* Queue::getFront() {
	if (!isEmpty()) 
		return head->character;
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

void Queue::addBack(class Character* c) {
	// if list is empty
	if (head == nullptr) {
		QueueNode* newNode = new QueueNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		newNode->character = c;
		head = newNode;
	}
	else {
		QueueNode* newNode = new QueueNode;
		newNode->character = c;
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
	//	cout << "Your queue is: ";
		QueueNode* temp = head;
		do {
			if(temp->next != head)
			{
				cout << temp->character->getName() << ", ";
				temp = temp->next;
			}
			else
			{
				cout << temp->character->getName() << " ";
				temp = temp->next;
			}
		} while (temp != head);	
	}
	else
		cout << "All fighters have perished!";
	
	cout << endl;
}

void Queue::printLosers() {
	int count = 1;
	cout << endl << "LOSERS QUEUE" << endl;
	cout << "In order of death from first killed to last: " << endl;
	if (!isEmpty()) {
	//	cout << "Your queue is: ";
		QueueNode* temp = head;
		do {
			cout << "[" << count << "] " << temp->character->getName() << endl;
			temp = temp->next;
			count++;
		} while (temp != head);	
	}
	else
		cout << "No fighters in loser queue!";
	
	cout << endl;
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
