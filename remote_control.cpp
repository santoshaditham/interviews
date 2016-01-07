/*Given a TV remote, write a script that would give directions to input some letters. 
Starting from the upper left-hand corner. 
If the buttons were in 3 columns, and you wanted to type "feed", 
you would want the output of the program to say 
"right, right, down, PRESS, left, PRESS, PRESS, left, PRESS" */

#include <iostream>
#include <vector>
using namespace std;

void find(char c, int& cur_pos){
  int idx = c - 'a';//ascii
  while(cur_pos!=idx){
    if(cur_pos/3 < idx/3){//go row below
      cur_pos+=3;
      cout << "down ";
    }
    else if(cur_pos/3 > idx/3){//go row above
      cur_pos-=3;
      cout << "up ";
    }
    else{//same row
      if(cur_pos<idx) {
        for(int i=0; i<(idx - cur_pos); i++) cout << "right ";
        cur_pos += (idx - cur_pos); 
      }
      if (cur_pos>idx) {
        for(int i=0; i<(cur_pos - idx); i++) cout << "left ";
        cur_pos -= (cur_pos - idx); 
      }
    }
  }
  cout << "PRESS" << endl;
}

int main(){
  string str = "feed";
  int cur_pos=0;
  for(auto& x: str){
    find(x, cur_pos);
  }
  return 0;
}
