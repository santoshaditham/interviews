    /* basic hash table with <key,value> as <int,string> */
    #include <iostream>
    #include <unordered_map>
    #include <string>
    using namespace std;
     
    class HashTable{
    unordered_map<int, string> _container;
    int size;  
    public:
      HashTable(){
        size=0;
      }
      void put(string val) {
        int key = ascii(val); 
        _container[key] = val;
        size++;
      }
      string find(string str) { 
        int key = ascii(str);
        return (_container.find(key) == _container.end()) ? str+" - not found!" : str+" - found!";
      }
      int getSize() {
        return size;
      }
    private:
      int ascii(string s){
          int score=0;
          for(auto& c : s){score += int(c);}
          return score;
      }
    };
     
    int main(){
      HashTable *my_hashtable = new HashTable();
      my_hashtable->put("Hello");
      my_hashtable->put("World");
      cout << "Number of elements in hash table : " << my_hashtable->getSize() << endl;
      cout << my_hashtable->find("Hello") << endl;
      cout << my_hashtable->find("Helloooooooo") << endl;
      return 0;
    }
