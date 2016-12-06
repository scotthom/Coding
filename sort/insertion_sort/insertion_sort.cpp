#include <iostream>
#include "sort.hpp"
#include "print.hpp"
#include <vector>
#include <string>

using namespace std;

// diffrence pointer to ellement and pointer to whole thing?

int main(int argc, char *argv[]){

	int a[6] = {6,5,7,3,9,1};
	int len_array = (sizeof(a)/sizeof(*a));

	insertion_sort(a,len_array);
	print_a(a,len_array);

} 
