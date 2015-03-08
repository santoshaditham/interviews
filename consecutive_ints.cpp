    /*the longest chain of consecutive integers in an unsorted set in linear time*/
    
    #include <iostream>
    #include <vector>
    using namespace std;
     
    int main() {
    	vector<int> a = {10,2,3,4,18,1,2,3,4,5,17,18,19};
    	int start = 0, end = 0, maxlen = 0;
    	int best_start = 0, best_end = 0;
    	for(int i=1; i<a.size()-1; i++){
    		if( a[i] != a[i-1]+1){
    			int len = end-start;
    			if(len > maxlen) {best_start = start; best_end = end;}
    			start=i;
    		}
    		else end=i;
    	}
     
    	for(int i=best_start; i<=best_end; i++) cout << a[i] << " ";
    	return 0;
    }
