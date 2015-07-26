/*
Given a n * m (n <= 100, m <= 100) board consists of chars in range of [a-z] and a word (like "yarn")
	b n x z 
	b r z n
	y a r z
You can start from any cell, and traverse to 4 directions, you cannot re-enter a cell. 
Question is, can you get a path that can make the given word in the board?
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool find_path(vector<vector<char>>* board, vector<vector<bool>>* v, string word, int pos, int r, int c){
	//up
	if(r-1>=0){
	if(!v->at(r-1).at(c)){
		if(word[pos] == board->at(r-1).at(c)){
			v->at(r-1).at(c)=true;
			if(find_path(board, v, word, pos+1, r-1, c)) {cout << word[pos] << endl;return true;}
			else return false;
		}
	}
	}
				
	//left
	if(c-1>=0){
	if(!v->at(r).at(c-1)){
		if(word[pos] == board->at(r).at(c-1)){
			v->at(r).at(c-1)=true;
			if(find_path(board, v, word, pos+1, r, c-1)) {cout << word[pos] << endl;return true;}
			else return false;
		}
	}
	}
	
	//right
	if(c+1 <= board->at(r).size()-1){
	if(!v->at(r).at(c+1)){
		if(word[pos] == board->at(r).at(c+1)){
			v->at(r).at(c+1)=true;
			if(find_path(board, v, word, pos+1, r, c+1)) {cout << word[pos] << endl;return true;}
			else return false;
		}
	}
	}
	
	//down
	if(r+1 <= board->size()-1){
	if(!v->at(r+1).at(c)){
		if(word[pos] == board->at(r+1).at(c)){
			v->at(r+1).at(c)=true;
			if(find_path(board, v, word, pos+1, r+1, c)) {cout << word[pos] << endl;return true;}
			else return false;
		}
	}
	}
}

int main() {
	vector<vector<char>> board = {{'b','n','x','z'},{'b','r','z','n'},{'y','a','r','z'}};
	string word = "yarn";
	
	//find position of first alpha in word within board
	int start_row=-1, start_col=-1;
	for(int r=0; r<board.size(); r++){
		for(int c=0; c<board.at(r).size(); c++){
			if(board.at(r).at(c)==word[0]) {
				start_row=r;
				start_col=c;
			}
		}
	}
	if(start_row==-1) {cout << "no path"; return 0;}
	
	//set all cells in board to not visited
	vector<vector<bool>> visited;
	for(int r=0; r<board.size(); r++){
		vector<bool> nr;
		visited.push_back(nr);
		for(int c=0; c<board.at(r).size(); c++){
			visited.at(r).push_back(false);
		}
	}
	
	//find path for remaining part of word
	find_path(&board, &visited, word, 1, start_row, start_col);
	cout << word[0] << endl;
	return 0;
}
