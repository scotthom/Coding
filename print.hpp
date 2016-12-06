# include <iostream>
#include <vector>

using namespace std; 

// ------------------------------------------ print array ------------------------------------------

template <typename T>
void print_a (T *a,int length)
{
	for(int i = 0; i < length; i++){ 
		cout << a[i] << endl; 				
	}	
}

// ------------------------------------------ print vector ------------------------------------------
template <typename T>
void print_v(vector<T> v)
{
	int len_v = v.size();
	for(int i = 0; i < len_v; i++){
		cout << v[i] << endl;
	}
}

