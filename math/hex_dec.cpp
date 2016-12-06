#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	cout << "inputs hexidecimal number: ";			// read in hexidecimal number
	string hex_num;
	cin >> hex_num;

	int num_dig = hex_num.length(); 

	int dec_num = 0;
	int num;

	for (int i = 0; i < num_dig; i++){				// covert hexidecimal to decimal
		 num = int(hex_num[4-(i+1)]) - 48;
		 dec_num += num*pow(16,i);
	}

	cout << "the hexidecimal number " << hex_num << " in decimal is " << dec_num << "." << endl;


} 