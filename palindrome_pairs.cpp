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

void palindrome_pairs(vector<string> *in){ //check for improvement
	map<string, int> my_map;
	vector<pair<int, int>> result;
	for(int i=0; i<in->size(); i++)
		my_map.emplace(in->at(i), i);
	
	for(int i=0; i<in->size(); i++){
		string rev = in->at(i);
		reverse(rev.begin(), rev.end());
		for(int c=0; c<rev.size(); c++){
			string rev_temp = rev.substr(c);
			auto it = my_map.find(rev_temp);
			if(it != my_map.end())
				result.push_back({i, it->second});
		}
	}
	
	print(&result);
}

int main() {
	vector<string> input = {"abcd", "xyz", "zyd", "cba", "pqr", "dcba"};
	palindrome_pairs(&input);
	return 0;
}
