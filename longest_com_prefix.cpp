    /* find longest common prefix among given strings */
    
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;
     
    void longest_com_prefix(vector<string> *s){
    string source = s->at(0);
    int i = 0;
    for(; i<source.size(); i++){
    	for(int j=1; j<s->size(); j++){
    		if(s->at(j)[i]!=source[i] || s->at(j).length() < i){
    			cout << source.substr(0, i);
    			return;
    		}
    	}
    }
    cout << source;
    }
     
    int main() {
        vector<string> s = {"abcd","ab","abc","abcdefgh"};
        longest_com_prefix(&s);
        return 0;
    }
