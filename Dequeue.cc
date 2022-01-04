/*
 * Dequeue.cpp
 *
 *  Created on: 29-Dec-2021
 *      Author: Admin
 */

#include <iostream>
#include <vector>

using namespace std;

template <class U>
class dequeueElement {
public:
	U item;
	dequeueElement<U> *next;
	dequeueElement<U> *prev;
};

template <class T>
class dequeue {
private:
	dequeueElement<T> *first, *last;

public:
	dequeue() {
		first = NULL;
		last = NULL;
	}

	bool isEmpty() {
		return (first == NULL);
	}

    void addFirst(T item) {
    	dequeueElement<T> *temp = new dequeueElement<T>;
    	temp->item = item;
    	if(!isEmpty()) {
    		temp->next = first;
    		temp->prev = NULL;
    		first = temp;
    	} else {
    		temp->next = NULL;
    		temp->prev = NULL;
    		first = last = temp;
    	}
    }

    void addLast(T item) {
    	dequeueElement<T> *temp = new dequeueElement<T>;
    	temp->item = item;
    	temp->next = NULL;
    	if(!isEmpty()) {
            dequeueElement<T> *oldLast = last;
            temp->prev = oldLast;
    		last->next = temp;
    		last = temp;
    	} else  {
    		temp->next = NULL;
    		temp->prev = NULL;
    		first = last = temp;
    	}
    }

    void removeFirst() {
    	if(!isEmpty()) {
    		dequeueElement<T> *temp = first;
    		if(temp->next != NULL) {
    			first = first->next;
    			first->prev = NULL;
    		} else {
    			cout << "Queue becomes empty" << endl;
    			first= last= NULL;
    		}
    		return;
    	}

    	cout << "Queue is Empty" << endl;
    	return;
    }

    void removeLast() {
    	if(!isEmpty()) {
    		dequeueElement<T> *oldLast = last;
    		if(oldLast->prev != NULL) {
    			dequeueElement<T> *temp = last->prev;
    			last = temp;
    			last->next = NULL;
    		} else {
    			cout << "Queue becomes empty" << endl;
    			first = last = NULL;
    		}
    		return;
    	}

    	cout << "Queue is Empty" << endl;
    	return;
    }

    void printItems() {
    	if(!isEmpty()) {
    		dequeueElement<T> *temp;
    		cout << "QueueItems" << endl;
    		for(temp = first; temp != NULL; temp = temp->next) {
    			cout << temp->item ;
    			if(temp->next != NULL) {
    				cout << "->";
    			}
    		}
    		cout << endl;
    		return;
    	}

    	cout << "Queue is Empty" << endl;
    	return;
    }
};


int main() {

	dequeue<int> obj;
	obj.addFirst(10);  //10
	obj.printItems();

	obj.addFirst(20);  //20->10
	obj.printItems();

	obj.addLast(40);   //20->10->40
	obj.printItems();

	obj.addFirst(30);  //30->20->10->40
	obj.printItems();

	obj.addFirst(50);  //50->30->20->10->40
	obj.printItems();

	obj.addLast(60);   //50->30->20->10->40->60
	obj.printItems();

	obj.removeFirst();  //30->20->10->40->60
	obj.printItems();

	obj.removeFirst();  //20->10->40->60
	obj.printItems();

	obj.removeFirst();  //10->40->60
	obj.printItems();

	obj.removeFirst();  //40->60
	obj.printItems();

	obj.removeFirst();  //60
	obj.printItems();

	obj.removeLast();   //No ouptut
	obj.printItems();

	obj.removeFirst();  //Queue is Empty
	obj.printItems();

	return 0;

}
