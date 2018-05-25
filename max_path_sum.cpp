/* max path sum in binary tree */

#include <iostream>
#include <algorithm> 
#include <climits>
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

int max_sum(Node* root, int& globalmax){
    if(root==NULL) return 0;
    
    int leftsum = max_sum(root->left, globalmax); // max on left
    int rightsum = max_sum(root->right, globalmax); // max on right
    int rootsum = max(root->data, root->data + max(leftsum, rightsum)); // max on root+left [or] root+right
    globalmax = max(globalmax, max(rootsum, root->data+leftsum+rightsum)); // max including root, left, right
    
    return rootsum;
}

int main() {
	Node* root = new Node(5);
	root->left = new Node(2);
  root->right = new Node(10);
  root->left->left = new Node(20);
  root->left->right = new Node(1);
  root->right->right = new Node(-25);
  root->right->right->left = new Node(3);
  root->right->right->right = new Node(4);
  
	int globalmax = INT_MIN;
	int rootsum = max_sum(root, globalmax);
	cout << globalmax;
  
	return 0;
}
