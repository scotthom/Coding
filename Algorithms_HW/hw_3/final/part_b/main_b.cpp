//
//  main.cpp
//  Linked_List_Template
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LinkedList<int> intList;
    
    cout << "Inserting: 5, 20, 7, -2\n";
    intList.add(5);
    intList.add(20);
    intList.add(7);
    intList.add(-2);
    
    cout << "The size of my list is " << intList.size() << endl;
    cout << "This is the content of my list: ";
    intList.print();
    
    cout << "Is 20 is in my list? " << (intList.contains(20) ? "yes" : "no") << endl;
    cout << "Is 10 is in my list? " << (intList.contains(10) ? "yes" : "no") << endl;
    cout << "Deleting: 20\n";
    intList.remove(20);
    
    cout << "This is the content of my list: ";
    intList.print();
    
    cout << "=================================\n";
    LinkedList<char> charList;
    
    cout << "Inserting: 'B', 't', 'V', '2'\n";
    charList.add('B');
    charList.add('t');
    charList.add('V');
    charList.add('2');
    
    cout << "The size of my list is " << charList.size() << endl;
    cout << "This is the content of my list: ";
    charList.print();
    
    cout << "Is 'V' is in my list? " << (charList.contains('V') ? "yes" : "no") << endl;
    cout << "Is 'v' is in my list? " << (charList.contains('v') ? "yes" : "no") << endl;
    cout << "Deleting: 'V'\n";
    charList.remove('V');
    
    cout << "This is the content of my list: ";
    charList.print();

    return 0;
}
