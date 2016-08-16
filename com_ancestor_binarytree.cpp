#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(Node* root, int d){
	Node* temp = new Node(d);
	if(root==NULL)
		root = temp;
	else if(root->left == NULL)
		root->left = temp;
	else if(root->right == NULL)
		root->right = temp;
	else
		insert(root->left, d);
}

bool covers(Node* root, int d){
	if(root == NULL) return false;
	if(root->data == d) return true;
	return(covers(root->left, d) || covers(root->right,d));
}

void common(Node* root, int d1, int d2){
	if(covers(root->left, d1) && covers(root->left, d2)) //left sub tree
		common(root->left, d1, d2);
	if(covers(root->right, d1) && covers(root->right, d2)) //right sub tree
		common(root->right, d1, d2);
	cout << "common ancestor: " << root->data << endl;
}

int main() {
	Node* root = new Node(5);
	insert(root, 10); insert(root, 5);
	insert(root, 1); insert(root, 2); insert(root, 3); 
	common(root, 5, 3);
	return 0;
}
