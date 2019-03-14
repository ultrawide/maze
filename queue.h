/*
 * queue.h
 *
 *  Created on: Mar 13, 2019
 *      Author: colin
 */
#include <string>
using namespace std;
#ifndef QUEUE_H_
#define QUEUE_H_

#define SIZE 100

class queue
{
	string* arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	queue(int size = SIZE);
	~queue();
	void dequeue();
	void enqueue(string value);
	string peek();
	int size();
	bool isEmpty();
	bool isFull();
};

#endif /* QUEUE_H_ */
