#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	char let;
	bool uppercase = true;
	bool alpha_char = false;

	while(alpha_char == false){						// keep checking if there's no alpha char.
		cin >> let;
		int let_i = int(let);
		
		if (let_i > 64 && let_i < 91){				//Check for uppercase char and alpha char
			alpha_char = true;
		}

		else if (let_i > 96 && let_i < 123){		//Check for lowercase char and alpha char
			alpha_char = true;
			uppercase = false;
		}

		
		if(alpha_char == true){						//If alpha char print if upper or lowercase char

			char let[2];

			if (uppercase)
				cout << let << " is uppercase." << endl;

			else 
				cout << let << " is lowercase." << endl;
		}

	}

} 