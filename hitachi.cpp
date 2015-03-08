/* Class Description:
Class Name: IntAnalysis
Purpose: To evaluate integer(s) based on predefined functions
Member variables: _values, a vector of integers to store all integers evaluated by this class
Member functions: 
    1. Name: add_integer
       Input Params: integer
       Return type: void
       Function: add a new integer to the _values collection of the class
    2. Name: even
       Input Params: integer
       Return type: boolean
       Function: to check if a given number is even(true) or odd(false). Reuse divisible_by_2() function.
    3. Name: divisible_by_<number>
       Input Params: integer
       Return type: boolean
       Function: to check if a given number is divisible by <number> where <number> is between 2 and 9. For code simplicity, we reuse some functions.    
    4. Name: already_evaluated
       Input Params: integer
       Return type: boolean
       Function: to check if a given number is evaluated before or not
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct BSTreeNode{
    int data;
    BSTreeNode* left;
    BSTreeNode* right;
    BSTreeNode(int _data, BSTreeNode* _left, BSTreeNode* _right){
        data = _data;
        left = _left;
        right = _right;
    }
};

class IntAnalysis{
  BSTreeNode* root;
  
  public:
    IntAnalysis(){root=new BSTreeNode(INT_MAX, NULL, NULL);};
    void add_integer(int);
    bool already_evaluated(int);
    bool even(int);
    bool divisible_by_2(int);
    bool divisible_by_3(int);
    bool divisible_by_4(int);
    bool divisible_by_5(int);
    bool divisible_by_6(int);
    bool divisible_by_7(int);
    bool divisible_by_8(int);
    bool divisible_by_9(int);
    friend void checkAll(int);
    ~IntAnalysis(){};//can delete the BSTree here
};

void IntAnalysis::add_integer(int n){
    if(root->data == INT_MAX){//empty tree
        root->data = n;
    }
    else{
        BSTreeNode* temp = root;
        BSTreeNode* _new = new BSTreeNode(n, NULL, NULL);
        while(temp!=NULL){
            if(temp->data > n){
                if(temp->left == NULL) {temp->left = _new;break;}
                else temp = temp->left;
            }
            else if(temp->data < n){
                if(temp->right == NULL) {temp->right = _new;break;}
                else temp = temp->right;
            } 
            else if(temp->data == n){
                //cout << "duplicate";
                break;
            }
        }
    }
}

bool IntAnalysis::already_evaluated(int n){
    if(root->data == INT_MAX) return false;//empty tree
    
    BSTreeNode* temp = root;
    while(temp!=NULL){
        if(temp->data > n){
            if(temp->left == NULL) return false;
            else temp = temp->left;
        }
        else if(temp->data < n){
            if(temp->right == NULL) return false;
            else temp = temp->right;
        } 
        else return true;
    }
    //return false;
}

bool IntAnalysis::even(int n){
    return divisible_by_2(n);
}

bool IntAnalysis::divisible_by_2(int n){
    add_integer(n);
    return (n%2==0)?true:false;
}

bool IntAnalysis::divisible_by_3(int n){
    add_integer(n);
    return (n%3==0)?true:false;
}

bool IntAnalysis::divisible_by_4(int n){
    add_integer(n);
    return (n%4==0)?true:false;
}

bool IntAnalysis::divisible_by_5(int n){
    add_integer(n);
    return (n%5==0)?true:false;    
}

bool IntAnalysis::divisible_by_6(int n){
    add_integer(n);
    return (divisible_by_2(n) && divisible_by_3(n))?true:false;    
}

bool IntAnalysis::divisible_by_7(int n){
    add_integer(n);
    return (n%7==0)?true:false;        
}

bool IntAnalysis::divisible_by_8(int n){
    add_integer(n);
    return (n%8==0)?true:false;       
}

bool IntAnalysis::divisible_by_9(int n){
    add_integer(n);
    return (n%9==0)?true:false;       
}

void checkAll(IntAnalysis _this, int n){
    if(!_this.already_evaluated(n)){
    	_this.add_integer(n);
    	if(_this.even(n)) cout << "even number" << endl;
    	if(_this.divisible_by_3(n)) cout << "divisble by 3" << endl;
    	if(_this.divisible_by_4(n)) cout << "divisble by 4" << endl;
    	if(_this.divisible_by_5(n)) cout << "divisble by 5" << endl;
    	if(_this.divisible_by_6(n)) cout << "divisble by 6" << endl;
    	if(_this.divisible_by_7(n)) cout << "divisble by 7" << endl;
    	if(_this.divisible_by_8(n)) cout << "divisble by 8" << endl;
    	if(_this.divisible_by_9(n)) cout << "divisble by 9" << endl;
    }
    else
    	cout << "already evaluated!" << endl;
}

int main(){
    IntAnalysis intAnal;
    vector<int> testCases = {1,2,2,2,2,234,534,65476,6,7,58,769,809,70,90};
    for(int x : testCases){
    	cout << "Test Case - " << x << endl;
        checkAll(intAnal, x);
        cout << endl;
    }
    return 0;
}
