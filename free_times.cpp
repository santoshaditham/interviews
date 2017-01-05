#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> Interval;

vector<Interval> get_free_time(vector<vector<Interval>>& users_availability){
	vector<Interval> out;
	map<int, vector<int>> schedules = {{9, {}}, {10, {}}, {11, {}}, {12, {}}, 
	{13, {}}, {14, {}}, {15, {}}, {16, {}}, {17, {}}};
	int p=0;
	for(auto ua : users_availability){
		p++;
		int free_at = 9; 
		for(auto i : ua){
			if(free_at < i.first){
				while(free_at < i.first) 
					schedules[free_at++].push_back(p);
			}
			else free_at = i.second;
		}
	}
	for(auto s : schedules){
		if(s.second.size() == p) 
			out.push_back(make_pair<int, int>((int)s.first, s.first+1));
	}
	return out;
}

int main() {
	vector<vector<Interval>> busy = {{{9,10},{15,16}},{{9,11},{14,15},{15,16},
	{16,17}},{{12,13}}};
	vector<Interval> avail = get_free_time(busy);
	for(auto a : avail) cout << a.first << " to " << a.second << endl;
	return 0;
}
