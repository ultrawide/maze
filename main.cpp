/*
 * main.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: colin
 */

#include "queue.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define MAZE_SIZE 5

int maze1[MAZE_SIZE][MAZE_SIZE] =
{
	{0, 1, 1, 1, 1},
	{0, 1, 1, 1, 1},
	{0, 1, 1, 1, 1},
	{0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0},
};

int maze2[MAZE_SIZE][MAZE_SIZE] =
{
	{0, 1, 1, 1, 1},
	{0, 0, 0, 1, 1},
	{0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
};

bool isDFSPath(int startR, int startC, int endR, int endC, int maze[][MAZE_SIZE]);
bool isBFSPath(int startR, int startC, int endR, int endC, int maze[][MAZE_SIZE]);
bool isVisited(int row, int col, set<string> mySet);

int main()
{
	if (isBFSPath(0, 0, 4, 4, maze2))
		cout << "There is a path! \n";
	else
		cout << "There is no path! \n";


	return 0;
}

bool isBFSPath(int startR, int startC, int endR, int endC, int maze[][MAZE_SIZE])
{
	if (startR == endR && startC == endC)
	{
		cout << "Reached the end point\n";
		return true;
	}

	set<string> visited;
	queue myQueue;

	string coordinate = to_string(startR) + to_string(startC);
	myQueue.enqueue(coordinate);

	while(!myQueue.isEmpty())
	{
		string endpoint = myQueue.peek();
		myQueue.dequeue();

		int currR = (stoi(endpoint)) / 10;
		int currC = (stoi(endpoint)) % 10;

		if (currR == endR && currC == endC)
		{
			cout << "Reached the end point\n";
			return true;
		}

		cout << "Traversing " << currR << ", " << currC << "\n";

		string coordinate = to_string(currR) + to_string(currC);
		visited.insert(coordinate);

		// for each adjacent node, check if it's visited
		// if visited, skip. otherwise add to queue

		if (maze[currC+1][currC] == 0 && currR+1 < MAZE_SIZE && !isVisited(currR+1, currC, visited))
		{
			string coordinate = to_string(currR+1) + to_string(currC);
			myQueue.enqueue(coordinate);
		}
		if (maze[currR-1][currC] == 0 && startR-1 >= 0 && !isVisited(currR-1, currC, visited))
		{
			string coordinate = to_string(currR-1) + to_string(currC);
			myQueue.enqueue(coordinate);
		}
		if (maze[currR][currC+1] == 0 && currC+1 < MAZE_SIZE && !isVisited(currR, currC+1, visited))
		{
			string coordinate = to_string(currR) + to_string(currC+1);
			myQueue.enqueue(coordinate);
		}
		if (maze[currR][currC-1] == 0 && currC-1 >= 0 && !isVisited(currR, currC-1, visited))
		{
			string coordinate = to_string(currR) + to_string(currC-1);
			myQueue.enqueue(coordinate);
		}
	}

	return false;
}

bool isDFSPath(int startR, int startC, int endR, int endC, int maze[][MAZE_SIZE])
{
	cout << "Traversing " << startR << ", " << startC << "\n";
	static set<string> visited;

	string coordinate = to_string(startR) + to_string(startC);
	visited.insert(coordinate);

	if (startR == endR && startC == endC)
	{
		cout << "Reached the end point\n";
		return true;
	}

	if (maze[startR+1][startC] == 0 && (startR+1) < MAZE_SIZE)
	{
		if (!isVisited(startR+1, startC, visited))
		{
			string coordinate = to_string(startR+1) + to_string(startC);
			visited.insert(coordinate);
			if (isDFSPath(startR+1, startC, endR, endC, maze))
				return true;
		}
	}

	if (maze[startR-1][startC] == 0 && (startR-1) >= 0)
	{
		if (!isVisited(startR-1, startC, visited))
		{
			string coordinate = to_string(startR-1) + to_string(startC);
			visited.insert(coordinate);
			if (isDFSPath(startR-1, startC, endR, endC, maze))
				return true;
		}

	}

	if (maze[startR][startC+1] == 0 && (startC+1) < MAZE_SIZE)
	{
		if (!isVisited(startR, startC+1, visited))
		{
			string coordinate = to_string(startR) + to_string(startC+1);
			visited.insert(coordinate);
			if (isDFSPath(startR, startC+1, endR, endC, maze))
				return true;
		}
	}

	if (maze[startR][startC-1] == 0 && (startC-1) >= 0)
	{
		if (!isVisited(startR, startC-1, visited))
		{
			string coordinate = to_string(startR) + to_string(startC-1);
			visited.insert(coordinate);
			if (isDFSPath(startR, startC-1, endR, endC, maze))
				return true;
		}
	}

	return false;
}

bool isVisited(int row, int col, set<string> mySet)
{
	string coordinate = to_string(row) + to_string(col);
	auto it = mySet.find(coordinate);

	if (it != mySet.end())
		return true;

	return false;
}
