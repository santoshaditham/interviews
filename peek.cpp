/* Implement peek using (a) next (b) hasnext functions */

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* ptr;
	
	Node(int d){ this->data = d; this->ptr = NULL; }
};

//create a list of nodes
class List{
	private:
	Node* root;
	
	public:
	List() { root = new Node(0); }
	~List() {}
	Node* getRoot() { return root; }
	void add(int d) {
		Node *new_node = new Node(d);
		Node *temp = root;
		while(temp->ptr != NULL) { temp = next(temp); }
		temp->ptr = new_node;
	}
	Node* next(Node* n) { return n->ptr; }
	bool hasnext(Node* n) { return (n->ptr==NULL) ? false : true; }
	int peek(Node* n) { return (hasnext(n)) ? next(n)->data : 0; }
};

int main() {
	List *new_list = new List();
	new_list->add(1); new_list->add(2); new_list->add(3);
	cout << "peek(root) = " << new_list->peek(new_list->getRoot()) << endl;
	return 0;
}
