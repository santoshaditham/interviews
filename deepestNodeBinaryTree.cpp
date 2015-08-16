/* get deepest and shallowest leaf node of binary tree */
#include <iostream>
#include <climits>
using namespace std;

class Node{
	private: 
		Node* left;
		Node* right;
		int value;
		int height;
	public:
		Node(int);
		void insert(int);
		int getHeight();
		int getValue();
		Node* getLeft();
		Node* getRight();
		void print();
		int deepest();
		int shallowest();
};

Node::Node(int value){
	this->left = NULL;
	this->right = NULL;
	this->value = value;
	this->height = 0;
}

int Node::getValue() { return this->value; }

int Node::getHeight(){ return this->height; }

Node* Node::getLeft(){ return this->left; }

Node* Node::getRight(){ return this->right; }

void Node::print(){
	cout << this->getValue()  << " at depth " << this->getHeight() << endl;
	if(this->left != NULL) this->getLeft()->print();
	if(this->right != NULL) this->getRight()->print();
}

void Node::insert(int value){
	Node* temp = new Node(value);
	if(this->left == NULL) { 
		this->left = temp; 
		temp->height = this->getHeight() +1;
		}
	else if(this->right == NULL) { 
		this->right = temp; 
		temp->height = this->getHeight() +1;
		}
	else this->left->insert(value);
}

int Node::deepest(){
	int left = 0, right = 0;
	if(this->left != NULL) left = this->getLeft()->deepest() +1; 
	if(this->right != NULL) right = this->getRight()->deepest() +1; 
	return (left > right) ? left : right;
}

int Node::shallowest(){
	int left = 0, right = 0;
	if(this->left != NULL) left = this->getLeft()->deepest() +1; 
	if(this->right != NULL) right = this->getRight()->deepest() +1; 
	return (left > right) ? right : left;
}

int main() {
	Node* root = new Node(INT_MIN);
	root->insert(1);root->insert(2);
	root->getLeft()->insert(0);
	root->getLeft()->insert(0);
	root->print();
	cout << "deepest leaf at depth " << root->deepest() << endl;
	cout << "shallowest leaf at depth " << root->shallowest() << endl;
	return 0;
}
