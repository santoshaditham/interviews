/* find lowest common ancestor of BST, from hackerrank
https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor */

#include <iostream>
#include <climits>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  
  Node(int i){
    data = i;
    left = NULL;
    right = NULL;
  }
};

Node* insert(Node* here, int val){
  if(val > here->data){ //right sub tree
    if(here->right != NULL) 
      return insert(here->right, val);
    else{
      Node* newNode = new Node(val);
      here->right = newNode;
      return newNode;
    }
  }
  else{ //left sub tree
    if(here->left != NULL) 
      return insert(here->left, val);
    else{
      Node* newNode = new Node(val);
      here->left = newNode;
      return newNode;
    }
  }
}

Node* common_ancestor1(Node* _from, Node* _this, Node* _that){
  if(_this->data < _from->data && _that->data > _from->data)
    return _from;
  else{
    if(_this->data < _from->data && _that->data < _from->data)
      return common_ancestor1(_from->left, _this, _that); //common ancestor is to the left
    else if(_this->data > _from->data && _that->data > _from->data)
      return common_ancestor1(_from->right, _this, _that); //common ancestor is to the right
    else
      return _this; // this and that are same
  }
}

Node* common_ancestor2(Node* from, int a, int b){
  if(from == NULL) return from;
  while(from != NULL){ //assume a < b
    if(from->data > b) from = from->left; //go left
    else if(from->data < a) from = from->right; //go right
    else break;
  }
  return from;
}

int main(){
  Node* root = new Node(5);
  insert(root, 2); insert(root, 7); insert(root, 1); insert(root, 6); insert(root, 10);
  Node* a = insert(root, 3); 
  Node* b = insert(root, 13);
  
  /* BST look like this 
        5
    2      7
  1  3   6  10
              13
  */
  
  cout << "common ancestor for (3,13) is " << common_ancestor1(root,a,b)->data << endl;
  cout << "common ancestor for (6,13) is " << common_ancestor2(root,6,13)->data << endl;
  return 0;
}
