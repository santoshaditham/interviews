/* reverse a single linked list */

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int d){
		this->data = d;
		this->next = NULL;
	}
};

void reverse(Node* current){
	Node* prev = NULL;
	Node* next = NULL;
	//store next and point to prev
	while(current != NULL){
		next = current->next;		
		current->next = prev;
		prev = current;
		current = next;
	}
	current = prev; //last element
}

int main() {
	Node* root = new Node(0);
	Node* temp = root;
	for(int i=1; i<5; i++){
		Node* n = new Node(i);
		temp->next = n;
		temp = n;
	}

	reverse(root);
	
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	
	return 0;
}
