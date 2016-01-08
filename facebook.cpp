// implement division without using divide operator

#include <iostream>
using namespace std;

int divide(int a, int b){
  if(a<b) return 0;
  if(b==0) return -1;
  if(a < 0 || b < 0) return -1;
  int count=0;
  while(a>=0){ // worst case O(a) but average case O(log  a)
    a = a-b;
    count++;
  }
  return (count-1);
}

int divide2(int a, int b){
  if(a<b) return 0;
  if(b==0) return -1;
  if(a < 0 || b < 0) return -1;
  int count=0, k=1;
  while(a >= 0){ // worst case O(log a) 
    if(a-b*k > 0){ 
      a = a-(b*k);
      count += k;
      k++;
    }
    else{
      k=1;
      a = a-b;
      count++;
    }
  }
  return (count-1);
}

int main() {
  cout << divide(20, 3);
  return 0;
}
