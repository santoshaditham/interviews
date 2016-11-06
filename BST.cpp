/* unsorted array to BST*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct bst_node{
    int data;
    bst_node* right;
    bst_node* left;
}bst_root;

void bst_insert(bst_node* _node, int d){
    //temp node
    bst_node* temp = new bst_node;
    temp->data=d;
    temp->right=NULL;
    temp->left=NULL;
    
    //empty BST
    if(_node==NULL){
        _node=temp;
        return;
    }
    
    //right subtree
    if(d > _node->data){
        if(_node->right==NULL){
            _node->right=temp;
            return;
        }
        else
            bst_insert(_node->right, d);
    }
    
    //left subtree
    if(d < _node->data){
        if(_node->left==NULL){
            _node->left=temp;
            return;
        }
        else
            bst_insert(_node->left, d);
    }

}

void print_preorder(bst_node* _node){
    if(_node->left!=NULL)
        print_preorder(_node->left);
    cout << _node->data << " ";
    if(_node->right!=NULL)
        print_preorder(_node->right);   
}

bool is_bst(bst_node* bnode, int min, int max){
	if(bnode==NULL) return true;
	if(bnode->data < min || bnode->data > max) return false;
	return is_bst(bnode->left, min, bnode->data) && is_bst(bnode->right, bnode->data, max);
}

int main()
{
   vector<int> input = {1,10,6,4,5};

   for(auto& x: input){
       bst_insert(&bst_root, x);
   }

   print_preorder(&bst_root);
   cout << is_bst(&bst_root, INT_MIN, INT_MAX); 
   return 0;
}
