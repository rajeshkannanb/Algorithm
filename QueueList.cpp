/*
 * Queue.cpp
 *
 *  Created on: 26-Oct-2021
 *  Author: B. Rajesh Kannan
 *  Description: Queue using linked list
 *  Disadvantage:
 *  1. Takes constant time in worst case.
 *  2. Almost takes 40 bytes per queue node including overhead.
 *
 */

#include <iostream>

using namespace std;

class queueElement {
public:
	string item;
	queueElement *next;
};

class queueOp {
private:
	queueElement *first, *last;
public:
	queueOp() {
		first = last = NULL;
	}

	bool isEmpty() {
		return (first == NULL);
	}

	void enqueue(string item) {
		cout << "Enqueue->" << item << endl;
		queueElement *oldLast = last;
		last = new queueElement;
		last->item = item;
		last->next = NULL;
		if(!isEmpty()) {
			oldLast->next = last;
		} else {
			first = last;
		}
	}

	string dequeue() {
		string item = "";
		if(!isEmpty()) {
			item = first->item;
			first = first->next;
		}
		return item;
	}

	void printQueue() {
		cout << "Queue Elements" << endl;
		if(!isEmpty()) {
			queueElement *node;
			for(node=first; node->next != NULL; node=node->next) {
				cout << node->item << "->";
			}
			cout << node->item << "->" << "NULL" << endl;
		} else {
			cout << "Queue is Empty" << endl;
		}
	}
};

int main() {
	string InputArray[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
	queueOp obj;
	for(auto i=0; i < (signed int)(sizeof(InputArray)/sizeof(InputArray[0])); ++i) {
		if(InputArray[i] == "-") {
			string item = obj.dequeue();
			cout << "dequeue->" << item << endl;
		} else {
			obj.enqueue(InputArray[i]);
		}

		obj.printQueue();

	}
	return 0;
}
