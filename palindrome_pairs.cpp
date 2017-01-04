/*palindrome pairs, assume no dups*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void print(vector<pair<int, int>> *res){
	for(auto r = res->begin();  r!=res->end(); r++)
		cout << r->first << " " << r->second << endl;
}

bool isPalindrome(string s){
	if(s.size()==1 || s.empty()) return true;
	int i = 0, j = s.size()-1;
	while(i<j){
		if(s[i] != s[j]) return false;
		i++; j--;
	}
	return true;
}

void palindrome_pairs(vector<string> *in){ //check for improvement, currently there are dups in result
	map<string, int> my_map;
	vector<pair<int, int>> result;
	for(int i=0; i<in->size(); i++)
		my_map.emplace(in->at(i), i);
	
	for(int i=0; i<in->size(); i++){
		string rev = in->at(i);
		reverse(rev.begin(), rev.end());
		//case 1: append at end
		for(int j=0; j<rev.size(); j++){
			string temp = rev.substr(j);
			auto it = my_map.find(temp);
			if(isPalindrome(in->at(i)+temp) && it != my_map.end())
				result.push_back({i, it->second});
		}
		//case 2: append at begin
		for(int j=0; j<rev.size(); j++){
			string temp = rev.substr(0, rev.size() - j);
			auto it = my_map.find(temp);
			if(isPalindrome(temp+in->at(i)) && it != my_map.end())
				result.push_back({it->second, i});
		}
	}
	
	print(&result);
}

int main() {
	vector<string> input = {"abcd", "xyz", "zyd", "cba", "pqr", "dcba"};
	palindrome_pairs(&input);
	return 0;
}
