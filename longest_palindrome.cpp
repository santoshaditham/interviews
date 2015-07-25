/* longest palindrome within a given string input */

#include <iostream>
#include <string>
using namespace std;

//input can be any size
//we can use a suffix tree or Manacher algorithm for better time complexity - O(n)
//but neither of them is more space efficient than this method

int longestPalindrome(string s, int center_this){
	int left_this = center_this-1;
	int right_this = center_this+1;
	while(s[left_this]==s[right_this]){//palindrome
		left_this--;right_this++;
	}
	return right_this-left_this-1;
}

int main() {
	string input;
	int result=0;
	cin >> input;
	if(input.size() == 2)
		cout << (input[0]==input[1])?2:0;
	if(input.size()>2){
		int i = input.size()/2; 
		int left = (input.size()%2!=0)?i:i-1;//even or odd
		int right = i;
		while(i>0){
			int l_result = longestPalindrome(input, left); result = (result>l_result)?result:l_result;
			int r_result = longestPalindrome(input, right); result = (result>r_result)?result:r_result; 
			left--;right++;i--;
		}
		cout << "longest palindrome is of size: " << result << endl;
	}
	return 0;
}
