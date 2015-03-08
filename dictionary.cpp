/* basic implementation of a dictionary */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;
vector<unordered_set<string>*> dictionary;

void look_up(string& word){
    int idx = word[0]-97;//ascii to index
    if(dictionary.at(idx)->find(word)!=dictionary.at(idx)->end())
        cout << "found" <<endl;
    else
        dictionary.at(idx)->emplace(word);
}

void fill_dictionary(){
    std::vector<string> words;
    words.push_back("abcd");words.push_back("ab");words.push_back("hello");words.push_back("bye");
    for(int i=0; i<words.size(); i++)
        look_up(words.at(i));
}

int main()
{
    for(int i=0; i<26; i++){//26 buckets, one per alphabet
        unordered_set<string>* bucket = new unordered_set<string>();
        dictionary.push_back(bucket);
    }
    fill_dictionary();
    string s = "hello";    
    look_up(s);  
    return 0;
}
