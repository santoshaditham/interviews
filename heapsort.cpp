#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>* input, int i, int j){
	int temp=input->at(i);
	input->at(i)=input->at(j);
	input->at(j)=temp;
}

void heapify(vector<int>* input, int i, int n){
	while(i<n){
		//get max child
		int check_with=2*i;
		if(check_with+1 < input->size() && 
			input->at(check_with+1) > input->at(check_with)) 
			check_with++;
		//swap if this > max child	
		if(input->at(i) > input->at(check_with)){ 
			swap(input, i, check_with);
			i=check_with;
		}
		else return;
	}
}

void build_heap(vector<int>* input){
	for(int i=0; i<input->size()/2; i++) {heapify(input, i, input->size());}
}

void heapsort(vector<int>* input){
	build_heap(input);
	int last_idx = input->size()-1;
	for(int i=last_idx; i>0; i--){
		swap(input, input->at(i), input->at(0));
		heapify(input, 0, i);
	}
}

int main() {
	vector<int> input {4,7,2,0,4,2,1,1,7};
	heapsort(&input);
	for(auto& x: input){cout << x << " ";}
	return 0;
}
