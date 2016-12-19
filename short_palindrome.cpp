// Given a string S, you are allowed to convert it to a palindrome by adding 0 or more characters in front of it. 
// Find the the shortest palindrome that you can create from S by applying the above transformation.
// This is a question by Bloomberg - Dec 2016

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
    int begin = 0, end = str.size() - 1;
    while(begin < end){
        if(str[begin] != str[end]) return false;
        begin++;
        end--;
    }
    return true;
}

string shortestPalindrome( string input){
    if(input.empty()) return "";
    if(isPalindrome(input)) return input;
    
    string duplicate = input;
    string temp;
    
    for(int i = input.size() - 1; i>0; i--){
        temp += input[i];
        duplicate = temp + input;
        if(isPalindrome(duplicate)){
            return duplicate;
        }
    }
    return duplicate;
}

int main(){
 string in = "aaabaaaa";
 cout << shortestPalindrome(in); 
 return 0;   
}
