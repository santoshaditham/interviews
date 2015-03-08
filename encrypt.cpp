/* simple encryption */

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "my name is santosh";
	string s2, s3;
	
	for(int i=0; i<s1.size(); i++)
		s2.append<int>(1,s1[i]+1);
	
	cout << "encrypted string is " << s2 << endl;
	for(int i=0; i<s2.size(); i++)
		s3.append<int>(1,s2[i]-1);

	cout << "decrypted string is " << s3 << endl;
	return 0;
}
