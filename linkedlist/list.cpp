#include <iostream>
#include <string>
#include "list.hpp"
using std::cin;
using std::cout;
using std::endl;

void addLinkAtHead(struct LinkedList* list, int value){
	if (list->head == NULL){
		// there are no objects in the list so create a newNode
		Node* newNode = new Node;

		//assign it the value from the parameter
		newNode->val = value;
		
		// set head and tail equal to newNode and have them point to each ptjer
		list->head = list->tail = newNode;
		list->head->next = list->tail;
		list->tail->prev = list->head;
		
		// make ends of list point to NULL
		list->head->prev = NULL;
		list->tail->next = NULL;
	}
	else {
		Node* newNode = new Node;
		newNode->val = value;
		newNode->next = list->head;
		newNode->prev = NULL;
		list->head->prev = newNode;
		list->head = newNode;
	}

	printList( list );
}

void addLinkAtTail(struct LinkedList* list, int value){
	if (list->head == NULL){
		// there are no objects in the list so create a newNode
		Node* newNode = new Node;

		//assign it the value from the parameter
		newNode->val = value;
		
		// set head and tail equal to newNode and have them point to each ptjer
		list->head = list->tail = newNode;
		list->head->next = list->tail;
		list->tail->prev = list->head;
		
		// make ends of list point to NULL
		list->head->prev = NULL;
		list->tail->next = NULL;
	}
	else {
		Node* newNode = new Node;
		newNode->val = value;
		newNode->next = NULL;
		newNode->prev = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
	}

	printList( list );
}

void deleteFirstNode( struct LinkedList* list ){
	// check if the list is empty and print out an error message if it is
	if ( list->head == NULL )
		cout << "The list is empty! Please choose another option." << endl << endl;
	// check if there is only one element in the list
	else if ( list->head->next == NULL ){
		delete(list->head);
		list->head = NULL;
		list->tail = NULL;
		cout << "The list is now empty." << endl << endl;
	}
	else {
		// create temp node and assign it the list head
		Node* tmp = list->head;
		
		// reassign pointers
		list->head->next->prev = NULL;
		list->head = list->head->next;

		// delete temp node (list head) and free the memory,
		delete(tmp);
		printList( list );
	}
}

void deleteLastNode( struct LinkedList* list ){
	// check if the list is empty and print out an error message if it is
	if ( list->head == NULL )
		cout << "The list is empty! Please choose another option." << endl << endl;
	// check if there is only one element in the list
	else if ( list->head->next == NULL ){
		delete(list->tail);
		list->head = NULL;
		list->tail = NULL;
		cout << "The list is now empty." << endl << endl;
	}
	else {
		// create temp node and assign it the list tail
		Node* tmp = list->tail;

		// reassign pointers
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;

		// delete temp node (list tail)
		delete( tmp );
		printList( list );
	}	
}

void printList( struct LinkedList* list ){
	if ( list->head == NULL )
		cout << "The list is empty." << endl << endl;
	else {
		cout << "Your linked list is: ";
	
		Node* curr = list->head;
		while ( curr != NULL ) {
			cout << curr->val << " ";
			curr = curr->next;
		}
		
		cout << endl << endl;
	}
}

void printListReverse( struct LinkedList* list ){
	if ( list->head != NULL ){
		cout << "Your linked list in REVERSE is: ";
	
		Node* curr = list->tail;
		while ( curr != NULL ) {
			cout << curr->val << " ";
			curr = curr->prev;
		}
	}
	else
		cout << "The list is empty and cannot be traversed.";	
	cout << endl << endl;
}

void deleteList( struct LinkedList* list ){
	Node* curr = list->head;
	Node* prev;
	while ( curr != NULL ){
		prev = curr;
		curr = curr->next;
		delete( prev ); 
	}
	list->head = NULL;
	list->tail = NULL;
	delete( list );
}
