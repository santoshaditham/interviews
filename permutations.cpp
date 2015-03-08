/* permutations of a string */
#include <iostream>
#include <string>
using namespace std;

void permutation(string prefix, string str) {
    int n = str.length();
    if (n == 0) cout << prefix << endl;
    else {
        for (int i = 0; i < n; i++)
            permutation(prefix + str.at(i), str.substr(0, i) + str.substr(i+1, n));
    }
}

int main(){
    string input = "abcd";
    permutation("", input);
    return 0;
}
