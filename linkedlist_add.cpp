// add 2 numbers represented by single linked list

#include <iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node(int i, node* n){
		this->val = i;
		this->next = n;
	}
};

void add(node* n1, node* n2){
	int length1=0, length2=0, carry=0;
	node* longer = NULL; node* shorter = NULL;
	//calculate length of numbers
	node* temp = n1; 
	while(temp->next != NULL) {length1++; temp = temp->next;} 
	temp = n2;
	while(temp->next != NULL) {length2++; temp = temp->next;} 
	//edge cases
	if(length1 == 0 && length2 ==0) {cout << "0" << endl; return;}
	if(length1 == 0 && length2 !=0){
		while(n2->next != NULL) {cout << n2->val;n2=n2->next;}
		return;
	}
	if(length2 == 0 && length1 !=0){
		while(n1->next != NULL) {cout << n1->val; n1=n1->next;}
		return;
	}
	//add shorter number to longer number
	if(length1 > length2){ shorter = n2; longer = n1; }
	else{ shorter = n1; longer = n2; }
	while(shorter->next != NULL){
		int sum = (longer->val + shorter->val + carry) % 10;
		carry = (longer->val + shorter->val + carry) / 10;
		longer->val = sum;
		longer = longer->next;
		shorter = shorter->next;
	}
	longer->val += carry;
	//output
	if(length1 > length2){
		while(n1->next != NULL) {cout << n1->val; n1=n1->next;}
		cout << endl;
	}
	else{
		while(n2->next != NULL) {cout << n2->val; n2=n2->next;}
		cout << endl;
	}
}

int main() {
	node* root1 = new node(5, NULL); //root points to lowest digit's place
	node* root2 = new node(7, NULL);
	node* temp;
	node* root1dup = root1; 
	for(int i=0; i<3; i++){//555
		temp = new node(5, NULL);
		root1dup->next = temp;
		root1dup = temp;
	}
	root1dup = root1; 
	while(root1dup->next != NULL) {cout << root1dup->val; root1dup = root1dup->next;}
	cout << endl;
	node* root2dup = root2;
	for(int i=0; i<2; i++){//77
		temp = new node(7, NULL);
		root2dup->next = temp;
		root2dup = temp;
	}
	root2dup = root2; 
	while(root2dup->next != NULL) {cout << root2dup->val; root2dup = root2dup->next;}
	cout << endl;
	
	add(root1, root2);//555 + 77

	return 0;
}
