/*given a number n, find largest number smaller than n formed using same digits as n*/
#include <iostream>
#include <string>
using namespace std;

string foo(int n){
  string str = to_string(n);
  if(n<10) return str;
  //start at back and look for 1st occurance of current digit < previous digit
  bool change = false;
  unsigned int idx=str.length()-1; 
  while(idx > 0){ 
    unsigned int cur = (unsigned int) str.at(idx);
    unsigned int prev = (unsigned int) str.at(idx-1); //previous
    if(cur < prev) {
      change = true;
      break;
    }
    idx--;
  }
  // swap digits
  if(change){
    char temp = str.at(idx);
    str.at(idx) = str.at(idx-1);
    str.at(idx-1) = temp;
  }
  return str;
}

int main() {
  int n = 34511; //assume n > 0
  cout << foo(n);
  return 0;
}
