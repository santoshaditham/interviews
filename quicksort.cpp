/*quick sort*/
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> *source, int here, int there){
	int temp = source->at(here);
	source->at(here)=source->at(there);
	source->at(there)=temp;
}

int partition(vector<int> *source, int start, int end){
	int pivot = source->at(end); 
	int smallptr=start-1; //pointer for elemets smaller than pivot
	for(int ptr=start; ptr<end; ptr++){ 
		//get smaller elements to left of pivot
		if(source->at(ptr)<pivot){
			swap(source, ptr, ++smallptr);
		}
	}
	swap(source,++smallptr,end);
	return smallptr;
}

void quicksort(vector<int> *source, int start, int end){
	if(start<end){
		int pivot = partition(source, start, end); //pivot is in sorted position
		quicksort(source,start,pivot-1); // sort 1st half, start until pivot
		quicksort(source,pivot+1,end); // sort remaining after pivot 
	}
}

int main() {
	vector<int> input = {4,3,13,6,1,2,4,7};
	if(input.size() < 2) return 0;
	quicksort(&input,0,input.size()-1);
	for(auto& x: input) cout<< x << " ";
	return 0;
}
