/*given a number n, find largest number smaller than n formed using same digits as n*/
#include <iostream>
#include <vector>
using namespace std;

int foo(int n){
	if(n<10) return n;
	
	int result=0, temp=n;
	vector<int> digits;
	//break number to digits
	while(temp > 0){
		digits.push_back(temp % 10);
		temp = temp/10;
	}
	//look for place where adjacent digits can be swapped
	int prev_max = digits.at(0);
	int prev_max_pos = 0;
	for(int i = 1; i < digits.size(); i++){ 
		if(digits.at(i) > prev_max)
		{ //swap
			int k = digits.at(i);
			digits.at(i) = prev_max;
			digits.at(prev_max_pos) = k;
			break;
		}
	}
	//output
	for(int i = digits.size()-1; i>=0; i--)
		result = (result*10) + digits.at(i);
	return result;
}

int main() {
	int n = 4321; //assume n > 0
	cout << foo(n) << endl;
	return 0;
}
