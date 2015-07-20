/* insertion sort */
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>* source, int here, int _this){
	int temp = source->at(_this);
	source->at(_this) = source->at(here);
	source->at(here) = temp;
}

int main() {
	vector<int> input = {5,6,2,3,8,1,23,11,6};
	if(input.size() < 2) return 0;
	for(int _this=1; _this < input.size(); _this++){
		for(int i=0; i<_this; i++){
			if(input[i]>input[_this]){
				swap(&input, i, _this);
			}
		}
	}
	for(auto& x: input){cout << x << " ";}
	return 0;
}
