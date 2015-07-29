/* There is an array filled with characters/numbers along with spaces. 
Each index contains only one ASCII character or a space. 
Give an algorithm that moves all spaces to the end or beginning of the array 
while keeping the rest of the characters in the original chronological order. */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void move_spaces(vector<char>* s){
	queue<int> space_idx;
	for(int i=0; i < s->size(); i++){
		if(s->at(i) == ' ') space_idx.push(i);
		else{
			if(!space_idx.empty()){
				s->at(space_idx.front()) = s->at(i);
				s->at(i) = ' ';
				space_idx.pop();
				space_idx.push(i);
			}
		}
	}
}

int main() {
	vector<char> source = {'h', 'e', ' ', ' ', ' ', 'l', ' ', 'l', ' ', ' ', 'o', '1'};
	for(auto& x: source) cout << x << " ";
	cout << endl;
	move_spaces(&source);
	for(auto& x: source) cout << x << " ";
	return 0;
}
