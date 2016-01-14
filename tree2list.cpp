//given a binary tree, create linked list of nodes (level-wise)

#include <iostream>
#include <vector>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
	node(int n){
		this->data = n;
		this->left = NULL;
		this->right = NULL;
	}
};

struct list_node{
	int data;
	list_node* next;
	list_node(int n){
		this->data = n;
		this->next = NULL;
	}
};

void insert(node* root, int val){
	if(root == NULL){
		node* temp = new node(val);
		root = temp;
	}
	else{
		if(root->data >= val){ //insert into left sub tree
			if(root->left != NULL)
				insert(root->left, val);
			else{
				node* temp = new node(val);
				root->left = temp;
			}
		}
		else { //insert into right sub tree
			if(root->right != NULL)
				insert(root->right, val);
			else{
				node* temp = new node(val);
				root->right = temp;
			}
		}
	}
}

void tree2list_levelwise(list_node* to, vector<node*> prev_level){
	vector<node*> this_level;
	for(auto& n : prev_level){
		if(n->left != NULL){
			to->next = new list_node(n->left->data);
			to = to->next;
			this_level.push_back(n->left);
		}
		if(n->right != NULL){
			to->next = new list_node(n->right->data);
			to = to->next;
			this_level.push_back(n->right);
		}
	}
	if(this_level.size() > 0) 
		tree2list_levelwise(to, this_level);
}

int main() {
	node* root = new node(4);
	insert(root, 1);insert(root, 6);insert(root, 0);insert(root, 3);
	insert(root, 5);insert(root, 7); insert(root, -1); insert(root, 8);
	list_node* lroot = new list_node(root->data);
	vector<node*> first_level;
	first_level.push_back(root);
	tree2list_levelwise(lroot, first_level);
	list_node* lroot_temp = lroot;
	while(lroot_temp != NULL){
		cout << lroot_temp->data << " -> ";
		lroot_temp = lroot_temp->next;
	}
	return 0;
}
