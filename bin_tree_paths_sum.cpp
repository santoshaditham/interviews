/*print all paths in a binary tree that sum to a given value*/

#include <iostream>
#include <vector>
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

//some insert function
Node* insert(Node* root, int d){
	Node* temp = new Node(d);
	if(root==NULL){
		root = temp;
		return root;
	}
	else if(root->left == NULL){
		root->left = temp;
		return root->left;
	}
	else if(root->right == NULL){
		root->right = temp;
		return root->right;
	}
}

void print(vector<int> buffer, int from){
	for(int i=from; i<buffer.size(); i++)
		cout << buffer.at(i) << " ";
	cout << endl;
}

// start at a node and traverse upwards until path sums to given value
void findPaths(Node* root, vector<int> buffer, int sum, int level){
	if(root==NULL) return;
	int temp1 = sum, temp2 = level;
	buffer.emplace_back(root->data);
	while(temp2 > -1){
		temp1 = temp1 - buffer.at(temp2);
		if(temp1 == 0) print(buffer, temp2);
		temp2--;
	}
	
	findPaths(root->left, buffer, sum, level+1);
	findPaths(root->right, buffer, sum, level+1);
}

int main() {
	Node* root = new Node(5);
	Node* n1 = insert(root, 10); 
	Node* n2 = insert(root, -5);
	Node* n11 = insert(n1, 1); Node* n12 = insert(n1, -12); 
	Node* n21 = insert(n2, -13); Node* n22 = insert(n2, 3); 
	Node* n211 = insert(n21, 16);
	
	vector<int> buffer;
	findPaths(root, buffer, 3, 0); // paths should sum to 3
	return 0;
}
