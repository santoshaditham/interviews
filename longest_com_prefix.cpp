    /* find longest common prefix among given strings */
    
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;
     
    void longest_com_prefix(vector<string>& input){
      string first = input.at(0);
      unsigned int i = 0;
      for(; i<first.size(); i++){
        for(unsigned int j=1; j < input.size(); j++){
          if((input.at(j)[i] != first[i]) || (input.at(j).length() < i)){
            cout << first.substr(0, i);
            return;
          }
        }
      }
      cout << first;
    }
     
    int main() {
        vector<string> input = {"abcd","ab","abc","abcdefgh"};
        longest_com_prefix(input);
        return 0;
    }
