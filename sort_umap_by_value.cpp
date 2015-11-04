/*sorting an unordered map by value*/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	std::unordered_map<std::string,int> mymap;
  	mymap = {{"Australia",1},{"U.S.",3},{"France",2},{"India",3},{"Nepal",1}};
  	for(auto& x : mymap)
  		cout << x.first << " " << x.second << endl;
  	std::multimap<int,std::string, greater<int>> mymap2;
  	for(auto& x : mymap)
  		mymap2.emplace(x.second, x.first);
    	for (auto& x : mymap2)
    	cout << x.first << " " << x.second << endl;
	return 0;
}
