/*
 * queueUsingArray.cpp
 *
 *  Created on: 02-Nov-2021
 *      Author: Admin
 */

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class queueWithArray {
private:
	vector<string> queueArray;
	int numberOfElements;
	int size;
	int head;
	int tail;

public:

	queueWithArray(int n) {
		numberOfElements = 0;
		head = -1;
		tail = -1;
		size = n;
		queueArray.assign(n,"");
	}

	void enqueue(string item) {
		if(numberOfElements == size) {
			resize(size * 2);
		}
		if((head == -1) && (tail == -1)) {
			head = tail = 0;
		} else {
			tail = (tail + 1) % size;
		}
		queueArray[tail] = item;
		numberOfElements++;
	}

	string dequeue() {
		string item = "";
		if(numberOfElements == 0) {
			cout << "No elements to dequeue" << endl;
		} else {
			if(numberOfElements == size/4) {
				resize(size/2);
			}
			item = queueArray[head];
			if(head == tail) {
				head = tail = -1;
			} else {
				head = (head + 1) % size;
			}
			numberOfElements--;
		}
		return item;
	}

    bool isEmpty() {
    	return ((head == -1) && (tail == -1));
    }

    void resize(int newSize) {
    	if(newSize > 0) {
    		size = newSize;
    		int newIndex = 0;
    		for(int i=head; i<=tail; ++i){
    			queueArray[newIndex] = queueArray[i];
    			newIndex++;
    		}
    		queueArray.resize(newSize);
    		head=0;
    		tail=newIndex-1;
    	} else {
    		return;
    	}
    }

    void printQueue() {
    	if(!isEmpty()) {
    		for(auto i=head; i<tail; i++) {
    			cout << queueArray[i] << "->";
    		}
    		cout << queueArray[tail] << endl;
    	} else {
    		cout << "Queue is Empty" << endl;
    	}
    }
};

int main() {
	string InputArray[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
	queueWithArray obj(2);
	for(auto i=0; i < (signed int)(sizeof(InputArray)/sizeof(InputArray[0])); ++i) {
		if(InputArray[i] == "-") {
			string item = obj.dequeue();
			cout << "dequeue->" << item << endl;
		} else {
			obj.enqueue(InputArray[i]);
			cout << "enqueue->" << InputArray[i] << endl;
		}

		obj.printQueue();

	}
	return 0;
}
