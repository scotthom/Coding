#include <iostream>
#include "bin_search_tree.hpp"

using namespace std; 

BinTree::BinTree(int x){
	root = new Node();
	newNode = root;
	linkNode = root;
	root->data = x;
}

BinTree::~BinTree(){

}

// check root size if smaller then root check left size smaller else check right side is smaller recursively. 

// action: write a recursive function to have two linkers traverse the tree according to x till an empty space is found and create new node and link

void BinTree::add(int x){
	if (x <= linkNode->data ){								// add node to empty spot
		if ((linkNode->left) == NULL){
			newNode = new Node();						// point linker1 to new Node
			newNode->data = x;							// use linker1 to set data of new Node to x
			linkNode->left = newNode;					// use linker2 to point parent node to new child node 
			newNode = root;								// move newNode and linkNode back to root to get ready to add new nodes
			linkNode = root;							 

		}

		else {											// Node spot is taken. check left subtree recur. for places to add new Node.
			newNode = newNode->left;
			linkNode = newNode;
			add(x);

		}
		
	}

	else{
		if ((linkNode->right) == NULL){
			newNode = new Node();						// point linker1 to new Node
			newNode->data = x;							// use linker1 to set data of new Node to x
			linkNode->right = newNode;					// use linker2 to point parent node to new child node 
			newNode = root;								// move newNode and linkNode back to root to get ready to add new nodes
			linkNode = root;							 

		}

		else {											// Node spot is taken. check left subtree recur. for places to add new Node.
			newNode = newNode->right;
			linkNode = newNode;
			add(x);

		}

	} 
	
}

void BinTree::insert(int z)
{
	Node *newNode = new Node;
	newNode->data = z;
	Node *y = NULL;
	Node *x = this->root;
	while(x != NULL){
		y = x;
		if(newNode->data < x->data)
			x = x->left;
		else 
			x = x->right;
	}
	if (y == NULL)
		newNode = this->root;
	else if (newNode->data <= y->data)
		y->left = newNode;
	else
		y->right = newNode;

}

void BinTree::print(Node *x)
{
	int height = 1;
	int nodes = 0;
	
	if(x == NULL){
		return;
	}
		 

	if (x == root){
		cout << "1: " << "(" << root->data << ")" << endl;
		++nodes;
		print(root->left);
		print(root->right);
	}

	else{
		cout << x->data << endl;
		++nodes;
		print(x->left);
		print(x->right);
	}

}

void BinTree::PreOrder(Node *x)
{
	cout << x->data << " ";

	if(x->left != NULL) 
		PreOrder(x->left);

	if(x->right != NULL)
		PreOrder(x->right);
}

void BinTree::InOrder(Node *x)
{
	if(x->left != NULL) 
		InOrder(x->left);

	cout << x->data << " ";

	if(x->right != NULL)
		InOrder(x->right);
}

void BinTree::PostOrder(Node *x){
	if (x->left != NULL)
		PostOrder(x->left);
	if (x->right != NULL)
		PostOrder(x->right);
	cout << x->data << endl;
}

Node *BinTree::Search(Node *x,int k)
{
	while(x != NULL and k != x->data)
		if(k < x->data)
			x = x->left;
		else 
			x = x->right;
	return x;
}

Node *BinTree::SearchParent(Node *x, int k){
	if(x->left == NULL && x->right == NULL)					//only root node, no ancestor
		return NULL;
	if((x->left != NULL && x->left->data == k) || (x->right != NULL && x->right->data == k))	// check if pointer x is parent of k 
		return x;
	if (k < x->data)						// move pointer x according to BST Property
		return SearchParent(x->left, k);
	if (k > x->data)
		return SearchParent(x->right, k);
}

Node *BinTree::Minimum(Node* x){
	while(x->left != NULL)
		x = x->left;
	return x;
}

Node *BinTree::Maximum(Node * x)
{
	while(x->right != NULL)
		x = x->right;
	return x;
}

Node *BinTree::Successor(Node* x){
	if (x->right != NULL)
		return Minimum(x->right);

	Node *y = this->SearchParent(this->root, x->data);

	while(y != NULL and x == y->right){
		x = y;
		cout << "x = " << x << endl;
		y = this->SearchParent(this->root, y->data);
		cout << "y = " << y << endl;
	}

	return y;
}



// implement by allocating a vector of bools with new and recording how to get to the node. Once at node delete and late us the vector to go to n-1
// spaces to node and set the ndoe that points to it to NULL

Node * BinTree::remove(Node *root, int x){
 	if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
      cout << "root = " << root << endl;
     }
  // if(root == NULL) return root;
  // else if(x < root->data) root->left = remove(root->left, x);
  // else if(x > root->data) root->right = remove(root->right, x);
  // else {
    // Case 1: No Child
    // if(root->left == NULL && root->right == NULL){
    //   delete root;
    //   root = NULL;
    // Case 2: one child
    // } else if(root->left == NULL){
    //   Node *temp = root;
    //   root = root->right;
    //   delete temp;
    // } 
    // else if(root->right == NULL){
    //   Node *temp = root;
    //   root = root->left;
    //   delete temp;
    // } 
    // else{
    //   Node *temp = FindMin(root->right);
    //   root->data = temp->data;
    //   root->right = Delete(root->right, temp->data);
    // }
  		// }
  
	// }
	return root;
}

// void BinTree::remove(int x)
// {
// 	static Node *delNode = newNode;
// 	if(root == NULL)			// figure out what to do if no nodes to delete
// 		;

// 	if (x < delNode->data ){								
// 		delNode = delNode->left;
// 		remove(x);
// 	}

// 	else if(x > delNode->data){
// 		delNode = delNode->right;
// 		remove(x);
// 	} 
// 	else {
// 		if(delNode->right == NULL && delNode->left == NULL){
// 			delete delNode;
// 			delNode = NULL;
// 			delNode = root;
// 		}
		
// 	}
// }