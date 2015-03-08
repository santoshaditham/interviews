/*given some array [....], change it to a < b > c < d > e < f...*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = {4,7,8,6,2,1};
	for(int i=0;i<a.size(); i++){
        if (i % 2 == 0){
            if (a[i+1] <= a[i]){
            	int temp=a[i+1];
            	a[i+1]=a[i];
            	a[i]=temp;
            }
        }
        else{
            if (a[i+1] >= a[i]){
            	int temp=a[i+1];
            	a[i+1]=a[i];
            	a[i]=temp;
            }
        }
	}
	for(auto x: a) cout << x << " ";
	return 0;
}
