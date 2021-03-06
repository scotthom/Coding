//when using delete if you want to permanently not have the pointer reffer to anything remember to set it to NULL

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node * next;

	~Node(){
		cout << "Node is deleted" << endl;
	}
		
};	

int main(int argc, char *argv[]){
	Node *newNode = new Node;
	Node *linkNode = newNode;
	newNode->data = 8;

	cout << newNode->data << endl;

	newNode = new Node;
	newNode->data = 12;
	cout << newNode->data << endl;
	linkNode->next = newNode;
	newNode = linkNode;

	delete linkNode->next;					

	cout << linkNode->data << endl;
	cout << (linkNode->next)->data << endl;

} 
