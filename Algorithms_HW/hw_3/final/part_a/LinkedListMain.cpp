#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]){
	LinkedList list;
	cout << "The size of the linked list = " << list.size() << endl;
	cout << "linkedlist contents = ";  
	list.print();
	list.add(1);
	list.add(2);
	list.add(3);
	cout << "linkedlist contents = ";  
	list.print();
	list.remove(2);
	cout << "linkedlist contents = ";  
	list.print();
	cout << list.index(1) << endl;
	cout << "linkedlist contents = ";  
	list.print();
}
