/* merge sort */
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>* source, int start, int mid, int end){
	vector<int> *temp = new vector<int>(source->size());
	int i=start, j=mid+1, k=start;
	// 2 pointers i,j for each half and pointer k for result
	while((i<=mid) && (j<=end)){
		// choose smallest of both halves and update in temp
		temp->at(k) = (source->at(i) <= source->at(j))?source->at(i):source->at(j);
		(source->at(i) <= source->at(j))?i++:j++;
		k++;
	}
	// copy leftover parts of both halves
	while(i<=mid){temp->at(k)=source->at(i);k++;i++;}
	while(j<=end){temp->at(k)=source->at(j);k++;j++;}
	// replace original with sorted output of temp 
	for(int x=start; x<=end; x++){source->at(x)=temp->at(x);}
	delete(temp);
}

void mergesort(vector<int>* source, int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(source, start, mid); //sort 1st half
		mergesort(source, mid+1, end); //sort 2nd half
		merge(source, start, mid, end); //merge both
	}
}

int main() {
	vector<int> input = {5,6,2,3,8,1,23,11,6};
	if(input.size() < 2) return 0;
	mergesort(&input, 0, input.size()-1);
	for(auto& x: input){cout << x << " ";}
	return 0;
}
