#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* next;
};

//O(n) insert, can be better if we maintain global ptr to end of list
void insert(Node* _node, int n){
    Node* _new = new Node;
    _new->data=n;
    _new->next=NULL;
    
    if(_node==NULL){
        _node = _new;
        return;
    }
    
    while(_node->next != NULL){
        _node = _node->next;
    }
    
    _node->next = _new;
}

void print(Node* _node){
    do{
       cout << _node->data << "->";
       _node = _node->next;
    }while(_node != NULL);
    cout << endl;
}

//O(nlogn) but not space efficient
void vector_sort(Node* _node){
    vector<int> temp;
    do{
       temp.push_back(_node->data);
       _node = _node->next;
    }while(_node != NULL);
    
    std::sort(temp.begin(), temp.end());
    
    for(auto x: temp)
        cout << x << "->";
    cout<<endl;    
    return;
}

bool isSorted(Node* _node){
    while(_node != NULL){
        if(_node->next!=NULL){
            if(_node->next->data < _node->data)
        	    return true;
            _node = _node->next;
        }
        else
            break;
    }
    return false;
}

//no extra memory wasted, worst-case complexity O(n2)
void inplace_sort(Node* start){
    bool keep_going = true;
    //as long as list isn't completely sorted
    while(keep_going){
    	Node* cur_max = start;
    	Node* _node = start;
        //sort
        while(_node != NULL){
            if(cur_max->data <= _node->data){
                cur_max=_node;
            }
            else{
                int temp = _node->data;
                _node->data = cur_max->data;
                cur_max->data = temp;
                cur_max = _node;
            }
            _node = _node->next;
        }
        //check
        keep_going = isSorted(start);
    }
    print(start);
    return;
}

int main()
{
   Node* root = new Node;root->data=5; root->next=NULL;
   //for(int i=0; i<10000; i++){
   insert(root, 4);insert(root, 1);insert(root, 2);insert(root, 7);
   //}
   cout << "input: " << endl;
   print(root);
   
   cout<<endl;cout<<endl;
   cout << "vector sort: " << endl;
   clock_t begin = clock();
   vector_sort(root);
   clock_t end = clock();
   double elapsed = double(end - begin);
   cout << "time taken: " << elapsed << endl;
   
   cout<<endl;cout<<endl;
   cout << "in-place sort: " << endl;
   begin = clock();
   inplace_sort(root);
   end = clock();
   elapsed = double(end - begin);
   cout << "time taken: " << elapsed << endl;
   
   return 0;
}
