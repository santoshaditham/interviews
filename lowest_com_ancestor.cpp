/* find lowest common ancestor of BST, from hackerrank
https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor */

node* lca(node* root, int v1, int v2)
{
    if(root == NULL) return root;
    if(v1>v2){ //make v1 the smaller, v2 the bigger
        int temp = v2;
        v2 = v1;
        v1 = temp;
    }
    while(root != NULL){
        if(root->data > v2) root = root->left; //left subtree
        else if(root->data < v1) root = root->right; //right subtree
        else break;
    }
    return root;
}
