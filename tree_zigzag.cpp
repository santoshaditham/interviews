// print binary tree in zigzag fashion

#include <iostream>
#include <stack>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
  node(int d){
      this->data = d;
      this->left = NULL;
      this->right = NULL;
  }
};

void zigzag(node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        cout << root->data << endl;
        return;
    }
    stack<node*> thislevel, nextlevel;
    thislevel.push(root);
    bool left = true;
    while(!thislevel.empty()){
        node* curr = thislevel.top();
        thislevel.pop();
        cout << curr->data << endl;
        if(left){
            if(curr->left!=NULL) nextlevel.push(curr->left);
            if(curr->right!=NULL) nextlevel.push(curr->right);
        }
        else{
            if(curr->right!=NULL) nextlevel.push(curr->right);
            if(curr->left!=NULL) nextlevel.push(curr->left);            
        }
        if(thislevel.empty() && !nextlevel.empty()){
            thislevel.swap(nextlevel);
            nextlevel = stack<node*>();
            left = !left;
        }
    }
}

int main()
{
   node* root = new node(5);
   root->left = new node(3);
   root->right = new node(8);
   root->left->left = new node(2);
   root->left->right = new node(4);
   root->left->left->left = new node(1);
   root->left->left->right = new node(3);
   zigzag(root);
   return 0;
}
