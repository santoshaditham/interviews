/*level wise print of binary tree*/

#include <iostream>
#include <queue>
using namespace std;

struct node{
	int data;
	int height;
	node* left;
	node* right;
	
	node(int d){
		this->data = d;
		this->height = 0;
		this->left=NULL;
		this->right=NULL;
	}
};

//update height when insert
struct node* insert(node* root, int d){
	node* temp = new node(d);
	if(root->data > d) root->left = temp;
	else root->right = temp;
	temp->height = root->height+1;
	return temp;
}

//print node, push children to queue, pop node
void print(node* root){
	std::queue<node*> q;
	q.push(root);
	int prev_height = -1;
	
	while(!q.empty()){
		if(q.front()->height > prev_height) cout << endl;
		cout << q.front()->data << " ";
		
		if(q.front()->left != NULL) q.push(q.front()->left);
		if(q.front()->right != NULL) q.push(q.front()->right);
		
		prev_height = q.front()->height;
		q.pop();
	}
}

//example
int main() {
	node* root = new node(7);
	node* n1 = insert(root, 4); 
	node* n2 = insert(root, 10);
	node* n3 = insert(n1, 2); 
	node* n4 = insert(n1, 5);	
	node* n5 = insert(n2, 12);
	node* n6 = insert(n3, 1);
	node* n7 = insert(n5, 15);
	
	print(root);
	
	return 0;
}
