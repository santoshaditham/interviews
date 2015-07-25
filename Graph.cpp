#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
struct Node{
    int data;
    bool visited;
    vector<Node*> *children;
    Node(int val){
    	this->data=val; 
    	this->visited=false; 
    	this->children=new vector<Node*>();
    }
};
 
class Graph{
    private:
    Node* start;
     
    public:
    Graph();
    ~Graph();
    void insert(Node*, Node*);
    void delet(Node*);
    void DFS(Node*, int);
    void BFS(Node*, int);
};
 
Graph::Graph(){
    Node* _new = new Node(INT_MAX);//some start point
    this->start = _new;
}
Graph::~Graph(){}

// new node always goes as child of some parent node 
void Graph::insert(Node* n, Node* p){
    if(p==NULL){this->start->children->push_back(n);}
    else{p->children->push_back(n);}
}

//to-be-completed
void Graph::delet(Node* n){}

//either value is found at current node or recursive DFS on current node 
void Graph::DFS(Node* from, int val){
	if(from==NULL) from=this->start;
	from->visited=true;
	if(from->data == val) {cout << "DFS found " << val << endl; return;}
	else{
    	if(!from->children->empty()){
    		for(auto child: *(from->children)){
    			if(!child->visited) DFS(child, val);
    		}
    	}
	}
}

//either value is found at current node or check all nodes at current level before recursive calls
void Graph::BFS(Node* from, int val){
	if(from==NULL) from=this->start;
	if(from->data == val) {cout << "BFS found " << val << endl; return;}
	else{
    	if(!from->children->empty()){
    		for(auto child: *(from->children)){
    			if(!child->visited){
    				child->visited=true;
    				if(child->data==val) {cout << "BFS found " << val << endl; return;}
    			}
    		}
    		for(auto child: *(from->children)){
    			BFS(child, val);
    		}
    	}
	}
}
 
int main() {
    Graph *g1 = new Graph();
    Node *n1 = new Node(5); Node *n2 = new Node(10);
    Node *n3 = new Node(1); Node *n4 = new Node(2);
    Node *n5 = new Node(15); Node *n6 = new Node(16); Node *n7 = new Node(17); 
    Node *n8 = new Node(500); Node *n9 = new Node(600); 
    g1->insert(n1, NULL); g1->insert(n3, n1); g1->insert(n4, n1);
    g1->insert(n2, NULL); g1->insert(n5, n2); g1->insert(n6, n2); g1->insert(n7, n2);
    g1->insert(n8, n3); g1->insert(n9, n3);
    
    g1->DFS(NULL, n9->data);
    g1->BFS(NULL, n7->data);
    
    g1->delet(n3);
     
    return 0;
}
