/*
 * socialNetworkConnectivity.cc
 *
 *  Created on: 24-Oct-2021
 *  Author: B. Rajesh Kannan
 *  Description:
 *  Social network connectivity. Given a social network containing nn members and a log file containing mm timestamps
 *  at which times pairs of members formed friendships, design an algorithm to determine the earliest time at which all
 *  members are connected (i.e., every member is a friend of a friend of a friend ... of a friend). Assume that the
 *  log file is sorted by timestamp and that friendship is an equivalence relation. The running time of your algorithm
 *  should be m \log nmlogn or better and use extra space proportional to nn.
 */

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class socialNetworkConnect {
private:
	int NumberOfFriends;
	vector<int> friendsArray;
	vector<int> weightArray;
public:
	socialNetworkConnect(int N) {
		NumberOfFriends = N;
		friendsArray.assign(NumberOfFriends,0);
		weightArray.assign(NumberOfFriends,1);
		for(auto i=0; i<NumberOfFriends; ++i) {
			friendsArray[i] = i;
		}
	}

	int root(int i){
		friendsArray[i] = friendsArray[friendsArray[i]];
		while(i != friendsArray[i]) {
			i = friendsArray[i];
		}
		return i;
	}

	int checkIfConnected(int p, int q) {
		return (root(p) == root(q));
	}

	void joinFriends(int p, int q, string timeStamp) {
		int i = root(p);
		int j = root(q);

		if(i == j) {
			return;
		}

		if(weightArray[i] < weightArray[j]) {
			friendsArray[i] = j;
			weightArray[j] += weightArray[i];
			if(weightArray[j] == NumberOfFriends) {
				cout << "All friends are connected at " << timeStamp << endl;
			}
		} else {
			friendsArray[j] = i;
			weightArray[i] += weightArray[j];
			if(weightArray[i] == NumberOfFriends) {
				cout << "All friends are connected at " << timeStamp << endl;
			}
		}

	}
};

int main() {
	socialNetworkConnect obj(6);
	if(!obj.checkIfConnected(1,5)) {
		obj.joinFriends(1,5, "2019-08-14 18:00:00");
	}
	if(!obj.checkIfConnected(2,4)) {
		obj.joinFriends(2,4, "2019-08-14 18:00:01");
	}
	if(!obj.checkIfConnected(1,3)) {
		obj.joinFriends(1,3, "2019-08-14 18:00:02");
	}
	if(!obj.checkIfConnected(5,2)) {
		obj.joinFriends(5,2, "2019-08-14 18:00:03");
	}
	if(!obj.checkIfConnected(0,3)) {
		obj.joinFriends(0,3,"2019-08-14 18:00:04");
	}
	if(!obj.checkIfConnected(2,1)) {
		obj.joinFriends(2,1,"2019-08-14 18:00:05");
	}
	return 0;
}
