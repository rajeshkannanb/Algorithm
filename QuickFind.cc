//============================================================================
// Name        : UnionFindAlgorithm.cpp
// Author      : B. Rajesh Kannan
// Version     : Quick Find Operation
// Copyright   : Your copyright notice
// Description : Time analysis. Quick find (1), Union (n), Initialize(n)
//               Disadvantage: N union commands on N objects - N2 time which is too slow to run and much expensive.
// Input       : 10
//				 union(4,3)
//				 union(3,8)
//				 union(6,5)
//				 union(9,4)
//				 union(2,1)
//				 connected(8,9)
//				 connected(5,0)
//				 union(5,0)
//				 union(7,2)
//				 union(6,1)
//============================================================================

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class UF {
private:
	vector<int> ufVector;
public:
	UF(int n) {
		ufVector.assign(n,0);
	    for(auto i=0; i < n; i++) {
	    	ufVector[i] = i;
	    }
	}

	void Union(int p, int q){
		int pid = ufVector[p];
		int qid = ufVector[q];
		int n = ufVector.size();

		for(auto i=0; i<n; i++) {
			if (ufVector[i] == pid) {
				ufVector[i] = qid;
			}
		}
	}

	//Quick Find
	bool connected(int p, int q) {
		return (ufVector[p] == ufVector[q]);
	}

	void printVector() {
		for(auto it=ufVector.begin();
			it != ufVector.end();
			++it) {
			cout << " " << *it;
		}
	}
};

int main() {

	int totalNumberOfElements;
	int p, q;

	cout << "Enter total number of elements" << endl;
	cin >> totalNumberOfElements;
	UF uf(totalNumberOfElements);

	//print the elements
	uf.printVector();

	try {
		cout << "Enter value of p->";
		cin >> p;
		cout << "Enter value of q->";
		cin >> q;

    	while((p <= totalNumberOfElements-1) && (q <= totalNumberOfElements-1)) {
    		//Check if connected
    		if(!uf.connected(p, q)) {
    		    uf.Union(p, q);
    		}

    		cout << "Enter value of p->";
    		cin >> p;
    		cout << "Enter value of q->";
    		cin >> q;
    	}

    	uf.printVector();

    } catch(int e) {
    	cout << "Exception" << e << endl;
    }
	return 0;
}
