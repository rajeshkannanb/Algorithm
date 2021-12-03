/*
 * QueueUsingTemplate.cpp
 *
 *  Created on: 28-Nov-2021
 *      Author: Admin
 */

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>
#include <typeinfo>
#include <type_traits>

using namespace std;

template <class T>
class queueWithArray {
private:
	vector<T> queueArray;
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
		queueArray.assign(n,T{});
	}

	void enqueue(T item) {
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

	T dequeue() {
		T item;
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
	queueWithArray<string> obj(2);
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

	int InputArray_int[] = {10,20,30,40,50,-1,20,-1,-1,60,-1,-1,-1,70};
	queueWithArray<int> obj_int(2);
	for(auto i=0; i < (signed int)(sizeof(InputArray_int)/sizeof(InputArray_int[0])); ++i) {
		if(InputArray_int[i] == -1) {
			int item = obj_int.dequeue();
			cout << "dequeue->" << item << endl;
		} else {
			obj_int.enqueue(InputArray_int[i]);
			cout << "enquque->" << InputArray_int[i] << endl;
		}

		obj_int.printQueue();
	}
	return 0;
}
