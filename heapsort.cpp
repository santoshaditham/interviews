/*in-place heap sort*/
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
		//does node i have children?
		if(2*i+1>n) return;
		//if so, get max child
		int check_with=2*i+1;
		if((check_with+1 <= n) && (input->at(check_with+1) > input->at(check_with))) 
			check_with++;
		//swap if this > max child	
		if(input->at(i) < input->at(check_with)){
			swap(input, i, check_with);
			i=check_with;
		}
		else return;
	}
}

void build_heap(vector<int>* input){
	int non_leaf = input->size()/2;
	for(int i=non_leaf; i>=0; i--) {heapify(input, i, input->size()-1);}
	for(auto& x: *input) cout << x << " ";
	cout << "built heap" << endl;
}

void heapsort(vector<int>* input){
	build_heap(input);
	int last_idx = input->size()-1;
	while(last_idx>0){
		swap(input, last_idx, 0);
		last_idx--;
		heapify(input, 0, last_idx);
		for(auto& x: *input) cout << x << " ";
		cout << "heapified" << endl;
	}
}

int main() {
	vector<int> input {19,17,16,12,9,15,1,2,11,7,3,10,14};
	heapsort(&input);
	for(auto& x: input){cout << x << " ";}
	return 0;
}
