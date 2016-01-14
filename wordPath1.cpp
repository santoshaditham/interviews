/*

Given a n * m (n <= 100, m <= 100) board consists of chars in range of [a-z]
    like
    b n x z 
    b r z n
    y a r z

    And a word (like "yarn"), you can start from any cell, and traverse to 4 directions, you cannot re-enter a cell, question is, can you get a path that can make the given word in the board?

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//this is O(n), can be made O(log n)
pair<int, int> find(vector<vector<char>> matrix, char ch){
	pair<int, int> result = make_pair<int, int> (-1,-1);
    for(int r=0; r<matrix.size(); r++) //row
    {
        for(int c=0; c<matrix[r].size(); c++) //column
        {
            if(matrix[r][c] == ch) 
                {
                	result.first = r;
                	result.second = c;
                	return result;
                }
        }
    }
    return result;
}

bool possible(pair<int, int> from, pair<int, int> to){
    if(from.first == -1000) //first check
        return true; 
    if(from.first == to.first)//same row
    { 
        if(from.second - to.second == 1 || from.second - to.second == -1)
            return true;
        else
            return false;
    }
    else if(from.second == to.second)//same column
    { 
        if(from.first - to.first == 1 || from.first - to.first == -1)
            return true;
        else
            return false;
    }
    return false;
}

bool isContains(vector<vector<char>> matrix, string word){
    if(matrix.size() == 0) return false; //no matrix
    if(word.size() == 0) return true; //no word
    pair<int, int> prev_position = make_pair<int, int>(-1000, -1000); 
    for(char ch : word){
        pair<int,int> position = find(matrix, ch); // find char in matrix   
        if(position.first != -1){
            if(!possible(prev_position, position)) //check if it is reachable
                return false;
            else
                prev_position = position;
        }
    }
    return true;
}

int main(){
    string word = "yarn";
    vector<vector<char>> matrix = {{'b','n','x','z'}, {'b','r','z','n'}, {'y','a','r','z'}};
    cout << "word is in matrix : " << isContains(matrix, word) << endl;
    return 0;
}
