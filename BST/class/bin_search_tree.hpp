#ifndef BINTREE_HPP
#define BINTREE_HPP

struct Node{		// creat node with a posibility of 0 - 2 children
		int data;
		Node *right;
		Node *left;

};

class BinTree {
	
	public:
		BinTree(int x);
		~BinTree();
		void add(int x);
		void insert(int x);
		Node *remove(Node *root, int x);
		void print(Node * x);
		void PreOrder(Node *x);
		void InOrder(Node *x);
		void PostOrder(Node *x);
		Node *Search(Node* x,int k);
		Node *SearchParent(Node *x, int k);
		Node *Maximum(Node * x);
		Node *Minimum(Node* x);
		Node *Successor(Node* x);
		Node *root;
		Node *newNode;
		Node *linkNode;
		int height;

};

#endif


