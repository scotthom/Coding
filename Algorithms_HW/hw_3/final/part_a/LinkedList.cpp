// name 1: Paul Ngouchet
// name 2: Scott Hom
#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{

Node *new_head = new Node();

head = new_head ;							
this->listSize = 0 ;
head->next = NULL ;

tail = new_head;				


}



LinkedList::~LinkedList()
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

int LinkedList::size()
{
return this->listSize;

}


bool LinkedList::contains(int x)
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


bool LinkedList::add(int x)
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


bool LinkedList::remove(int x)
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

void LinkedList::print()
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

