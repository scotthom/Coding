//name 1: Paul Ngouchet
//name 2: Scott Hom
#include "MaxProduct.h"

MaxProductClass::MaxProductClass()
{

	
}


long MaxProductClass::MaxProduct(string filename)
{



int number;
int multiple= 1 ;
int biggest_multiple = 0;
vector<int> numbers;
vector<int> multiples;
vector<int> list_multiples;

int count = 0 ;
ifstream myfile;
myfile.open(filename);

while (!myfile.eof())
{
 
	myfile >> number ;

	numbers.push_back(number);
}

myfile.close();
int a = 0 ;
for( int i = 0 ; i < numbers.size(); i++)
{

	//cout << " current number is " << numbers[i] << endl ;
if( numbers[i] == -999999)
{

if ( multiples.size() == 0 )
	break;
else{
	sort(multiples.begin() , multiples.end());
	biggest_multiple = multiples[multiples.size() - 1];
	list_multiples.push_back(biggest_multiple);
	a = 0 ;
	multiple = 1 ;
	multiples.clear();
	cout<< biggest_multiple << endl ;
	continue ;
}
}

multiple = multiple * numbers[i];
multiples.push_back(multiple);
a++ ;

if( a == 3)
{	
//cout << " Getting there ? " << endl ;

//cout << " the multiples are " << multiple << endl;
	
	multiple = 1 ;
	i = i - 2 ;
	a = 0 ;
}

}

sort(list_multiples.begin(), list_multiples.end());

return (long) list_multiples[list_multiples.size() -1] ;

}