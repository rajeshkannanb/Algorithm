/*
 * stack.cpp
 *
 *  Created on: 26-Oct-2021
 *  Author: B. Rajesh Kannan
 *  Description: Stack using linked list.
 *  Disadvantage:
 *  1. Takes constant time in worst case.
 *  2. Almost takes 40 bytes per stack node including overhead.
 */

#include <iostream>

using namespace std;

class Node {
public:
	string item;
	Node *next;
};

class StackString {
private:
	Node *firstNode = NULL;
	Node *newNode = NULL;
	int nodeSize = 0;
public:
	void push(string item) {
	  Node *oldFirstNode = firstNode;
	  newNode = new Node;
	  newNode->item = item;
	  newNode->next = oldFirstNode;
	  firstNode = newNode;
	}

	string pop() {
		string item = "";
		if(!isEmpty()) {
		   item = firstNode->item;
		   firstNode = firstNode->next;
		}
		return item;
	}

	bool isEmpty() {
		return (firstNode == NULL);
	}

	void printList() {
		if(!isEmpty()) {
			nodeSize = 0;
			for(Node *item = firstNode; item != NULL; item=item->next) {
			   cout << item->item << endl;
			   nodeSize = nodeSize + sizeof(item);
		    }
		} else {
			cout << "Stack is empty" << endl;
		}

		cout<< "Size Occupied in bytes ->" << nodeSize << endl;
	}

};

int main() {
	string InputArray[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    StackString obj;
	for(auto i=0; i < (signed int)(sizeof(InputArray)/sizeof(InputArray[0])); ++i) {
		if(InputArray[i] == "-") {
			string item = obj.pop();
			cout << "pop->" << item << endl;
		} else {
			obj.push(InputArray[i]);
		}
		obj.printList();
	}
	return 0;
}
