//
//  LinkedList.h
//  Linked_List_Template
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>



/* A singly-linked list node */
struct Node
{
    float data;
    Node *next;
};


/* A class for a singly-linked list */
class LinkedList
{
public:
  LinkedList();       // Constructor: Inits an empty singly-linked list
  ~LinkedList();      // Destructor: Destroys the singly-linked list 
  int size();         // Returns the size of the singly-linked list
  bool contains(int x);  // Returns true if x is in the list, otherwise returns false
  bool add(int x);    // Adds x if not already in the list and returns true, otherwise returns false
  bool remove(int x); // Removes x if in the list and returns true, otherwise returns false
  void print();       // Prints the content of the singly-linked list
  float index(int x); // Retuns the number at x given that x = 0 is the head.

private:
  Node *head;         // Pointer to head of singly-linked list
  Node *tail;         // Pointer to tail of singly-linked lis
  int listSize;       // Size of singly-linked list
};

#endif /* LinkedList_h */
