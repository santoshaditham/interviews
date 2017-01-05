#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> foo(vector<double> in){
	vector<int> out;
	int floor_sum = 0;
	double actual_sum = 0.0;
	for(double d : in){
		out.push_back(floor(d));
		floor_sum += floor(d);
		actual_sum += d;
	}
	double gap = actual_sum - (double) floor_sum;
	for(int i=0; i<floor(gap); i++)
		out[i]++;
	return out;
}

int main() {
	vector<double> input = {30.3, 2.4, 3.5};
	vector<int> output = foo(input);
	for(auto x : output) cout << x << " ";
	return 0;
}
