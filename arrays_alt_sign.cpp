/* Given an array of numbers, return the longest substring in which 
the difference between every consecutive number pair 
varies with a difference in sign (i.e. +-+-) */

#include <iostream>
using namespace std;

void longest_alt_sign(int arr[], int arr_size, int from, int begin, int end) {
	bool prev_sign = false, cur_sign = true; //this works only for given example
	int temp_begin=from, temp_end=from;
	
	for(int i = temp_begin; i<arr_size-1; i++) {
		( arr[i+1] - arr[i] > 0 ) ? cur_sign = true : cur_sign = false;
		if(prev_sign != cur_sign) {
			temp_end=i+1;
			prev_sign = cur_sign;
		}
		else  // 2 consecutive same signs
			break;
	}

	// stop condition
	if(temp_end == arr_size-1) {
		if((temp_end - temp_begin) > (end-begin)) {
			end = temp_end;
			begin = temp_begin;
		}
		for(int j=begin; j<=end; j++){
			cout << arr[j] << " ";
		}
		return;
	}
	
	// else continue
	if((temp_end - temp_begin) > (end-begin)) 
		longest_alt_sign(arr, arr_size, temp_end+1, temp_begin, temp_end);
	else
		longest_alt_sign(arr, arr_size, temp_end+1, begin, end);
}

int main(){
	int arr[] = {1,2,-1,-1,4,1,2,0,4,-2,6,7};
	longest_alt_sign(arr, 12, 0, 0, 0);
	return 0;
}
