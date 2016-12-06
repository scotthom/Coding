
//Runtime of CuckooHashTable:

// *  hashCode fuction runtime = 3n = Θ(n)

//- best case: T(n) = Θ(n). The hash table will encounter no collisions. It will in best case linear time because to add each number 
//  takes two calls of the hash function (3 lines) which happnes in 6n = Θ(n) plus empty slot check, set value, and increment currentSize 
//  which happen in Θ(1) plus print which takes ((number of numbers added)/(size of table))n = Θ(n). Therefore T(n) = Θ(n) + Θ(n) + Θ(1) is
// Θ(n).

// - Worst Case: T(n) = Θ(n^3). let m = size of table and input n = m. m numbers will tried to bed added with an infinite loop at the end.
//	 The T(n) is a multiple of the number of collisions times the cost T(n) of the number collisions. The number of collisions is Σ from 1 to (m-1) (a number can't collided 
//	 with itself so m-1). Each collision T(n) cost T(n) of the number being inserted times the total numbers so far thats a linear runtime (see above)
// 	 times Σ 1 to m. The sum is T(n) = Θ(n^2). the sum times the linear runtime is T(n) = (Θ(n^2))(Θ(n)) = Θ(n^3). to do collisions it tkaes 4 times called
//   the hash function plus constant work = T(n) = 12n + Θ(1) = Θ(n). Thoe re assignements are done ((n-1)^2 + (n-1)/2) = Θ(n^2). Therefore T(n) = (Θ(n^2))(Θ(n))
//   = Θ(n^3). The extra runtime to account for an infinite loop is one extra collision which is T(n) = Θ(n). The runtime is then T(n) = 2Θ(n^3) + Θ(n) = Θ(n^3) 

#include <iostream>
#include <vector>
#include "CuckooHashTable.h"

using namespace std;

CuckooHashTable::CuckooHashTable(){
	vector<string> T1 (LOGICAL_SIZE);				//create an empty 2 x 13 array
	vector<string> T2 (LOGICAL_SIZE);
	contents.push_back(vector<string> (T1));
	contents.push_back(vector<string> (T2));
	this->currentSize = 0 ;
}


void CuckooHashTable::add(string value)
{ 

	static int which = 0;
	which = 0 ;
		
	int times_rehashed = 0;			

	string temp;

while(true){		//continously search for open slot for ellement

		if ((contents[which][hashCode(value,which)]).empty() == true)		// add number to slot in table if empty	
			{
				contents[which][hashCode(value,which)] = value ;
				currentSize++;	
				break;			
			}

		else 
			{	
			  																
					temp = contents[which][hashCode(value,which)];			// collisions: save collided into var to temp and set collidinf value to slot.      
					contents[which][hashCode(value,which)] = value;
					
					if(which == 1)	// If number was collided into send it to the opposite table. 						
				  {							
				  	which = 0;
				  }
			  		else
				  {
				  	which = 1 ;				
				  	}	

					if((contents[which][hashCode(temp,which)]).empty() == true)		//add collided into number to new slot
					{	
						contents[which][hashCode(temp,which)] = temp;	
						currentSize++;
						break;

						}			
					else
					{
							if(times_rehashed == currentSize)										//detetct infinite loop
								{
							cout << "Error hashtable is caught in an infinite loop\n" << endl;
							exit(EXIT_FAILURE);
						}	
					
						times_rehashed++;
					
					}

			}
	}
	
}

int CuckooHashTable::hashCode(string value, int which)
{
	

	int h1 = 0;
	int h2 = 0; 
	int number = stoi(value);	

		if (which == 1)				// hashing to T2 slot if number was in T1  
		{
			h2 = 11-(number%11);
			return h2;
		}

	else
		{
			h1 = number%13;			// hashing to T1 slot if number was in T2 and by default has to T1 slot.
			return h1;

		} 

		
}





void CuckooHashTable::print()
{


cout << "Table 1:" << endl ;				// print 2 x 13 vector slots. If nothing is in slot print a "-".
for(int i = 0 ; i < 13 ; i++)
	{

	if(contents[0][i].empty() == true)
		cout<< "-" << endl;
	else
		cout << contents[0][i] << endl;

	}


cout << "Table 2:" << endl ;
for(int i = 0 ; i < 13 ; i++)
	{
	
	if(contents[1][i].empty() == true)
		cout<< "-" << endl;
	else
		cout << contents[1][i] << endl;

	}	




}