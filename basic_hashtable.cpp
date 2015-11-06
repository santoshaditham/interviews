    /* basic hash table with <key,value> as <int,string> */
    #include <iostream>
    #include <unordered_map>
    #include <string>
    using namespace std;
     
    class Hash{
    unordered_map<int, string*> _container;
    public:
      void put(string& val) {int key = ascii(val); _container[key] = &val;}
      string* get(int key) {return _container[key];}
    private:
      int ascii(string& s){
          int score=0;
          for(auto& c : s){score += int(c);}
          return score;
      }
    };
     
    int main(){
    Hash *my_object = new Hash();
     
    string s1 = "abcd"; my_object->put(s1);
    string s2 = "xyz"; my_object->put(s2);
    string s3 = "pqr"; my_object->put(s3);
     
    cout << my_object->get(394) << "\t" << *my_object->get(394) << endl;
     
    return 0;
    }
