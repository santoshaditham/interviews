    /* basic hash table with <key,value> as <int,string> */
    #include <iostream>
    #include <unordered_map>
    #include <string>
    using namespace std;
     
    class Hash{
    unordered_map<int, string*> _container;
    public:
      void put(int key, string& val) {_container[key] = &val;};
      string* get(int key) {return _container[key];};
      int count() {return _container.size();};
    };
     
    int main(){
    Hash *my_object = new Hash();
    int objects=1;
     
    string s1 = "hello"; my_object->put(1, s1);
    string s2 = "hello"; my_object->put(2, s2);
    string s3 = "world"; my_object->put(3, s3);
    string s4 = "world"; my_object->put(4, s4);
     
    objects = my_object->count();
    while(objects>0){
    	cout << my_object->get(objects) << "\t" << *my_object->get(objects) << endl;
    	objects--;
    }
     
    return 0;
    }
