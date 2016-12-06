// name 1: Paul Ngouchet
// name 2: Scott Hom
//  LinkedList.h
//  Linked_List_Template
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <iostream>
using namespace std;


/* A singly-linked list node */


/* A class for a singly-linked list */
template<typename T>
class LinkedList
{
public:
  LinkedList();       // Constructor: Inits an empty singly-linked list
  ~LinkedList();      // Destructor: Destroys the singly-linked list 
  int size();         // Returns the size of the singly-linked list
  bool contains(T x); // Returns true if x is in the list, otherwise returns false
  bool add(T x);      // Adds x if not already in the list and returns true, otherwise returns false
  bool remove(T x);   // Removes x if in the list and returns true, otherwise returns false
  void print(); 

  struct Node
  {
      T data;
      Node *next;
  };                  // Prints the content of the singly-linked list

private:
  Node *head;
  Node *tail;
  int listSize;       // Size of singly-linked list
  
};





template<typename T>
LinkedList<T>::LinkedList()
{

Node *new_head = new Node();

head = new_head ;
this->listSize = 0 ;
head->next = NULL ;

tail = new_head;


}


template<typename T>
LinkedList<T>::~LinkedList()
{
Node *node_it = new Node();
Node *help_delete = new Node();
node_it = head ;


while(true)
{
if(node_it == NULL)
  break;

help_delete= node_it->next;
delete node_it;
node_it = help_delete;

}



}


template<typename T>
int LinkedList<T>::size()
{
return this->listSize;

}

template<typename T>
bool LinkedList<T>::contains(T x)
{
Node *node_it = new Node();
node_it = head ;



if(listSize == 0)
  return false;

if(listSize > 0)
    {


    while(true)
      {
        if( node_it->data != x)
          {
    
            node_it = node_it->next;
            if( node_it == NULL)
              break;

            
          }
        else
          {
            return true;
          }


      }
    


  }
return false ;
}

template<typename T>
bool LinkedList<T>::add(T x)
{



if(listSize == 0)
  {
  head->data = x;
  listSize++;
    return true ;
  }


Node *node_it = new Node();

node_it = head ;

if(listSize > 0)
  {

  while(true)
    {
      if( node_it->data != x)
        {
          node_it = node_it->next;
          if( node_it == NULL)
            break;

          continue;

        }
      else
        {
          return false;
        }


    }

    Node *add_node = new Node();
    add_node->next = NULL ;
    add_node->data = x ;
    tail->next= add_node;
    tail= add_node;
    

    listSize++;


}
  return true ;





  }

template<typename T>
bool LinkedList<T>::remove(T x)
{
Node *remove_node = new Node(); 
Node *node_it = new Node();
Node *previous_node = new Node();
node_it = head ;

if(listSize == 0)
  return false;

if(listSize > 0)
    {


    while(true)
      {
        if( node_it->data != x)
          {
            previous_node = node_it;
            node_it = node_it->next;
            if( node_it == NULL)
              break;

            continue;

          }
        else
          {
          previous_node->next = node_it->next;
          delete node_it;
            return true;
          }


      }


    



  }

return false ;
}

template<typename T>
void LinkedList<T>::print()
{
  Node *node_it = new Node();
  node_it = this->head ;


while(true)
  {

    cout<< node_it->data << " " ;
    node_it = node_it->next;


    if(node_it == NULL)
      break;
  }

  cout << endl ;

}


#endif /* LinkedList_h */
