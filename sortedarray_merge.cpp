/* merge 2 sorted arrays */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge(vector<int> big, vector<int> small){
	int s = small.size();
	int b = big.size();
	for(int i=0; i<s; i++) //create enough space in big to fit small
		big.push_back(INT_MAX);
	int i=b-1, j=s-1, k=big.size()-1; //have 3 pointers
	while(j>=0 && i>=0){ //add elemenets into their proper positions, starting from end
		if(small.at(j) >= big.at(i))
			big.at(k--) = small.at(j--);
		else
			big.at(k--) = big.at(i--);
	}
	if(i>=0){//update leftovers
		while(i>=0)
			big.at(k--) = big.at(i--);
	}
	if(j>=0){//update leftovers
		while(j>=0)
			big.at(k--) = small.at(j--);
	}
	for(auto& x : big) //result
		cout << x << " " ;
}

int main() {
	vector<int> v1 = {1,1,1,1,1};
	vector<int> v2 = {0,0,0};
	if(v1.size() >= v2.size())
		merge(v1,v2);
	else
		merge(v2,v1);
	return 0;
}
