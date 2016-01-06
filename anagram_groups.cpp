/*group list of anagrams*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string sort(string& str){
  map<int, char> ordered_str;
  string out;
  for(auto& ch: str) ordered_str.emplace( (int)(ch-'a'), ch);
  for(auto& x: ordered_str) out = out + x.second;
  return out;
}

void anagram_groups(vector<string>& source){
  multimap<string, string> mymap;
  for(auto& str: source) mymap.emplace(sort(str), str);
  for(auto& x: mymap) cout << x.second << endl;
}

int main() {
  vector<string> source = {"abc", "cba", "xyz", "yzx"};
  for(auto& x: source) cout << x << " ";
  cout << endl;
  anagram_groups(source);
  return 0;
}
