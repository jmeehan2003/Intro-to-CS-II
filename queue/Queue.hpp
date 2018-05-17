#ifndef QUEUE_HPP


struct QueueNode {
	QueueNode* next;
	QueueNode* prev;
	int val;
};


class Queue {
private:
	QueueNode* head = nullptr;

public:
	Queue(){};
	~Queue();
	int getFront();
	void removeFront();
	void addBack(int val);
	bool isEmpty();
	void printQueue();
};


#endif
