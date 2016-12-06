#include <iostream>
#include "bin_search_tree.hpp"

using namespace std;

int main(int argc, char *argv[]){

	BinTree tree(7); 

	int arr[] = {1,9,37,3,8,10,2,5,4,6};

	int len_arr = (sizeof(arr)/sizeof(*arr)); 

	for(int i = 0; i < len_arr; i++){
		tree.add(arr[i]);
	}

	tree.PreOrder(tree.root);

} 


