#ifndef LIST_HPP

struct Node {
	int val;
	Node* prev;
	Node* next;
};

struct LinkedList {
	Node* head = NULL;
	Node* tail = NULL;
	//int size // not used for this implementation
};

void addLinkAtHead( struct LinkedList*, int );
void addLinkAtTail( struct LinkedList*, int );
void deleteFirstNode( struct LinkedList* );
void deleteLastNode( struct LinkedList* );
void printList( struct LinkedList* );
void printListReverse( struct LinkedList* );
void deleteList( struct LinkedList* );

#endif
