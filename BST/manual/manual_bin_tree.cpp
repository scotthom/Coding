#include <iostream>

using namespace std;


struct Node{		// creat node with a posibility of 0 - 2 children
		int data;
		Node *right;
		Node *left;

		~Node(){
			cout << "Node is deleted" << endl;
		}

};

int main(int argc, char *argv[]){
	Node *root = new Node;		//creat root Node with root pointer and linker
	Node *newNode;
	Node *linkNode;
	linkNode = root;
	newNode = root;
	root->data = 8;
	cout << "root node: " << newNode->data << endl;

	newNode = new Node;	
	newNode->data = 10; 
	linkNode->right = newNode;
	linkNode = newNode;

	cout << "right node 1: " << newNode->data << endl;

	newNode = new Node;
	newNode->data = 21;
	linkNode->right = newNode;
	linkNode = newNode;

	cout << "right node 2: " << newNode->data << endl;

	linkNode = root;
	newNode = root;

	Node *it = root;
	it = it->right;
	it = it->right;
	delete it;
	it = NULL;
	it = root;

	if ((root->right)->right == NULL){
		cout << "The node has become NULL so it is effectively gone" << endl;
	}

	cout << ((root->right)->data) << endl;
	cout << (((root->right)->right)->data) << endl;


	// delete ((linkNode->right)->right);			//delete node 
	// (linkNode->right)->right = NULL;


	// cout << endl;

	// bool visit_root = false;

	// for(int i = 0; i < 3; i++){
	// 	if(visit_root == false){
	// 		cout << "root node: " << linkNode->data << endl;
	// 		visit_root = true;
	// 	}

	// 	else{
	// 		if(linkNode->right != NULL){
	// 			linkNode = (linkNode->right);
	// 			cout << "right node 1: " << linkNode->data << endl;
	// 		}

	// 		else
	// 			cout << "This node is NULL" << endl;
	// 	}

	// }



} 
