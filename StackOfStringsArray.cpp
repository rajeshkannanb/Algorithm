/*
 * stackUsingArray.cpp
 *
 *  Created on: 28-Oct-2021
 *  Author: B. Rajesh Kannan
 *
 */

#include <iostream>
#include <vector>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

class stackArray {
private:
	vector<string> arrayOfStrings;
	int numberOfElements;
	int position = 0;
public:
	stackArray(int n) {
		numberOfElements = n;
		arrayOfStrings.assign(n,"");
	}

	void push(string item){
		if(position < numberOfElements) {
			arrayOfStrings[position++] = item;
		} else {
			cout << "No room to push item" << endl;
			cout << "Resizing the array" << endl;
			int newSize = 2 * numberOfElements;
			arrayOfStrings.resize(newSize);
			arrayOfStrings[position++] = item;
			numberOfElements = newSize;
			//arrayOfStrings.assign(newSize-numberOfElements,"");
			//printArray();
		}
	}

	string pop() {
		string item = arrayOfStrings[--position];
		//to avoid loitering - to hold reference when not required.
		arrayOfStrings[position] = "";
		if((position > 0) && (position==numberOfElements/4)) {
			cout << "Shrink Array" << endl;
			int newSize = numberOfElements/2;
			arrayOfStrings.resize(newSize);
			numberOfElements = newSize;
		}
		return item;
	}

	void printArray() {
		cout << "Array Contents" << endl;
		cout << "Array Size->" << numberOfElements << endl;
		cout << "Current Position" << position << endl;
		for(auto i=0; i<position; ++i) {
			if(arrayOfStrings[i] != "") {
				cout << arrayOfStrings[i] << endl;
			}
		}
	}

};

int main() {
	string InputArray[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
	stackArray obj(2);
	for(auto i=0; i < (signed int)(sizeof(InputArray)/sizeof(InputArray[0])); ++i) {
		if(InputArray[i] == "-") {
			string item = obj.pop();
			cout << "pop->" << item << endl;
		} else {
			obj.push(InputArray[i]);
		}

		obj.printArray();

	}
	return 0;
}
