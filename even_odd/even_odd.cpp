#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	int num = 0;

	if (num%2 == 0 && num != 0){
		cout << num << " is even." << endl;
	}

	else if (num%2 != 0 && num != 0){
		cout << num << " is odd." << endl;
	}

	else 
		cout << num << " is zero" << endl;

}
