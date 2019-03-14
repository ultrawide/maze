/*
 * queue.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: colin
 */

#include "queue.h"
#include <iostream>

using namespace std;

queue::queue(int size)
{
	arr = new string[size];
	capacity = size;
	front = 0;
	rear = 0;
	count = 0;
}

queue::~queue()
{
	delete[] arr;
}

void queue::dequeue()
{
	if (isEmpty())
	{
		cout << "array is empty, cannot dequeue\n";
		return;
	}

	cout << "removing " << arr[front] << '\n';
	front = (front + 1) % capacity;
	count--;
}

void queue::enqueue(string value)
{
	if (isFull())
	{
		cout << "array is full, cannot enqueue\n";
		return;
	}

	cout << "adding " << value << '\n';
	arr[rear] = value;
	rear = (rear + 1) % capacity;
	count++;
}

string queue::peek()
{
	return arr[front];
}

int queue::size()
{
	return count;
}

bool queue::isEmpty()
{
	return count == 0;
}

bool queue::isFull()
{
	return count == capacity;
}


