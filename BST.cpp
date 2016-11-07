/* unsorted array to BST*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct node{
    int data;
    node* right;
    node* left;
}bst_root;

void bst_insert(node* bnode, int d){
    //temp node
    node* temp = new node;
    temp->data=d;
    temp->right=NULL;
    temp->left=NULL;
    
    //empty BST
    if(bnode==NULL){
        bnode=temp;
        return;
    }
    
    //right subtree
    if(d > bnode->data){
        if(bnode->right==NULL){
            bnode->right=temp;
            return;
        }
        else
            bst_insert(bnode->right, d);
    }
    
    //left subtree
    if(d < bnode->data){
        if(bnode->left==NULL){
            bnode->left=temp;
            return;
        }
        else
            bst_insert(bnode->left, d);
    }

}

node* find(node* root, int d){
	if(root==NULL) return root;
	if(root->data > d) find(root->left, d);
	else if(root->data < d) find(root->right, d);
	else return root;
}

int height(node* root, node* n){
	if(root==NULL) return 0;
	if(root->data > n->data) return 1+ height(root->left, n);
	else if(root->data < n->data) return 1+ height(root->right, n);
	else return 0;	
}

void print_preorder(node* bnode){
    if(bnode->left!=NULL)
        print_preorder(bnode->left);
    cout << bnode->data << " ";
    if(bnode->right!=NULL)
        print_preorder(bnode->right);   
}

void print_inorder(node* bnode){
    cout << bnode->data << " ";
    if(bnode->left!=NULL)
        print_inorder(bnode->left);
    if(bnode->right!=NULL)
        print_inorder(bnode->right); 
}

bool is_bst(node* bnode, int min, int max){
	if(bnode==NULL) return true;
	if(bnode->data < min || bnode->data > max) return false;
	return is_bst(bnode->left, min, bnode->data) && is_bst(bnode->right, bnode->data, max);
}

int lca(node* root, int n1, int n2){
	if(root==NULL) return -1;
	if(root->data > n1 && root->data > n2) lca(root->left, n1, n2);
	else if(root->data < n1 && root->data < n2) lca(root->right, n1, n2);
	else return root->data;
}

bool is_subtree(node* n1, node* n2){
	node* temp = find(n1, n2->data); 
	return (n2 == temp);
}

void print_by_level(node* root){
	if(root==NULL) return;
	queue<node*> my_q;
	my_q.push(root);
	int prev = 0;
	while(!my_q.empty()){
		if(height(root, my_q.front()) != prev) cout << endl; 
		prev = height(root, my_q.front()); 
		cout << my_q.front()->data << " ";
		if(my_q.front()->left != NULL) my_q.push(my_q.front()->left);
		if(my_q.front()->right != NULL) my_q.push(my_q.front()->right);
		my_q.pop();
	}
}

int main()
{
   vector<int> input = {2,10,6,4,5,1,3,12,11,13};
   for(auto& x: input)
       bst_insert(&bst_root, x);

   cout << "pre-order: " << endl; print_preorder(&bst_root); cout << endl; // non decreasing
   cout << "in-order: " << endl; print_inorder(&bst_root); cout << endl;
   cout << "this a BST: " << is_bst(&bst_root, INT_MIN, INT_MAX) << endl; 
   cout << "lca(3,12): " << lca(&bst_root,3,12) << endl;
   node* n1 = find(&bst_root, 2);
   node* n2 = find(&bst_root, 4);
   cout << "tree from node(" << n2->data << ") is subtree of tree from node(" << n1->data << ") : " << is_subtree(n1, n2) << endl; 
   cout << "print by level: " << endl; print_by_level(&bst_root);
   return 0;
}
