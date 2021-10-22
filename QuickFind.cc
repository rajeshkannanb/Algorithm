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
//  Quick find defect:
//  1. Union too expensive (N array accesses)
//  2. Trees are flat. Too expensive to keep the trees flat.
//
//  Quick union defect:
//  1. Trees can get tall.
//  2. Find too expensive (could be N array accesses)
//
//  Weighted Quick Union defect:
//  1. To address the issues in Quick find and quick union this algorithm is introduced.
//  2. Small trees are attached to large trees.
//  3. Size array is used to identify the weight of tree based on number of nodes.
//  4. For every union operation, the node with less weight is attached with node with heavy weight.
//  5. After attaching the nodes as given in step #4, the heavy weight node is updated with new weight.
//  6. The weight is based on size of nodes.
//
//  Run time analysis:
//  Algorithm              			Initialize  union    connected   worst-case time
//  quick-find                			N         N         1            M * N
//  quick-union               			N         N         N            M * N
//  weighted QU               			N        log N    log N          N + M log N
//  QU+path compression       			N        log N    log N          N + M log N
//  Weighted QU + Path compression		N        log N    log N          N + M log * N
//
//  Weighted Quick Union with Path compression : M union-find operations on N objects makes <= c(N + Mlog*N) array access.
//============================================================================

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class UF {
private:
	vector<int> ufVector;
	vector<int> ufSizeVector;
public:
	UF(int n)
	{
		ufVector.assign(n,0);
		ufSizeVector.assign(n,1);
	    for(auto i=0; i < n; i++) {
	    	ufVector[i] = i;
	    }
	}

	//Quick Find
	void QFUnion(int p, int q){
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
	bool QFconnected(int p, int q) {
		return (ufVector[p] == ufVector[q]);
	}

	int QUroot(int element) {
		while(element != ufVector[element]) {
			element = ufVector[element];
		}
		return element;
	}

	//Quick-Union algorithm
	int QUconnected(int p, int q) {
		return (QUroot(p) == QUroot(q));
	}

	void QUUnion(int p, int q) {
		int i = QUroot(p);
		int j = QUroot(q);
		ufVector[i] = j;
	}

    //Weighted Quick Union algorithm
	int WQUConnected(int p, int q) {
		return (QUroot(p) == QUroot(q));
	}

    void WQUUnion(int p, int q) {
    	int i = QUroot(p);
    	int j = QUroot(q);

    	//If i and j are equal, they points to same root. So, the size of tree is same where p points to and q points to.
    	if (i == j) return;

    	cout << "ufSizeVector[" << i << "]->" << ufSizeVector[i] << endl;
    	cout << "ufSizeVector[" << j << "]->" << ufSizeVector[j] << endl;

    	if(ufSizeVector[i] < ufSizeVector[j]) {
    		ufVector[i] = j;
    		ufSizeVector[j] += ufSizeVector[i];
    	} else {
    		ufVector[j] = i;
    		ufSizeVector[i] += ufSizeVector[j];
    	}

    	cout << "After update" << endl;
    	cout << "ufSizeVector[" << i << "]->" << ufSizeVector[i] << endl;
    	cout << "ufSizeVector[" << j << "]->" << ufSizeVector[j] << endl;
    }

    //Weighted quick union with path compression
    int WQUPCroot(int i) {
    	while (i != ufVector[i]) {
    		ufVector[i] = ufVector[ufVector[i]];
    		i = ufVector[i];
    	}
    	return i;
    }

    int WQUPCConnected(int p, int q) {
    	return (WQUPCroot(p) == WQUPCroot(q));
    }

    void WQUPCUnion(int p,int q) {
    	int i = WQUPCroot(p);
        int j = WQUPCroot(q);

        if (i == j) return;

    	cout << "ufSizeVector[" << i << "]->" << ufSizeVector[i] << endl;
    	cout << "ufSizeVector[" << j << "]->" << ufSizeVector[j] << endl;

        if(ufSizeVector[i] < ufSizeVector[j]) {
        	ufVector[i] = j;
        	ufSizeVector[j] += ufSizeVector[i];
        } else {
        	ufVector[j] = i;
        	ufSizeVector[i] += ufSizeVector[j];
        }

        cout << "After tree update" << endl;
    	cout << "ufSizeVector[" << i << "]->" << ufSizeVector[i] << endl;
    	cout << "ufSizeVector[" << j << "]->" << ufSizeVector[j] << endl;

    }

	void printVector() {
		for(auto it=ufVector.begin();
			it != ufVector.end();
			++it) {
			cout << " " << *it;
		}
		cout << endl;
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

    		//Check if connected with quick find algorithm
    		/*if(!uf.QFconnected(p, q)) {
    		    uf.QFUnion(p, q);
    		}*/

    		//Check if connected with quick union algorithm
    		/*if(!uf.QUconnected(p, q)) {
    			uf.QUUnion(p, q);
    		}*/

    		//Check if connected with weighted quick union algorithm
    		//if(!uf.WQUConnected(p, q)) {
    		//	uf.WQUUnion(p, q);
    		//}

    		//Check if connected with weighted quick union with path compression algorithm
    		if(!uf.WQUPCConnected(p, q)) {
    			uf.WQUPCUnion(p, q);
    		}

    		uf.printVector();

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
