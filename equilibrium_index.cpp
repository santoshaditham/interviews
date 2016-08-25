/* Given an array, print index of element when sum of elements to its left equals sum to its right */

#include <iostream>
#include <vector>
using namespace std;

int foo(vector<int> arr){
  int total=0, cur_sum=0;
  for(auto i : arr) total += i;
  for(int i=0; i<arr.size(); i++){
    cur_sum += arr.at(i);
    if(cur_sum - arr.at(i) == total - cur_sum)
      return i;
  }
  return -1;
}

int main() {
  vector<int> arr = {1,2,3,3};
  cout << foo(arr);
  return 0;
}
