#include "Coordinates.h"
#include "Couples.h"

// PAUL NGOUCHET 
// LAB PARTNER SCOTT HOM

//WARNING REALLY INTENSE CODE, SIMPLE PRINCIPLE BUT REALLY HARD TO IMPLEMENT AND MAKE IT EFFICIENT 
// I USED MOSTLY MAPS IN MY CODE FOR A FASTER COODE AND I BROKE INTO CLASSES TO BETTER CONTROL THE ALGORTITHM

// ------ Analysis ------
// We disregarded reading in the files characters as being the detemeriner of n, because the number points are
// what are actually being input into the collinear line finder function. The for loop that creates the couples runs in 
// (n^2-n) because it is combination of n choose 2. The other major loop runs in (1/2)((n^2 )-n), 
//because it is derived from the sum from 1 to n of n – k, which represents everytime a collinear pair is found 
// the number of points that can be part of the collinear line reduces by one. The runtime T(n) = ((n^2) – n) + (1/2)((n^2) -n) = (3/2)((n^2) - n)



bool collinear_couples(Couples* first , Couples* second)
{

	bool test_col = first->equationTest(second->point1);
	if(test_col == true )
		return true;

	return false;
}


int main()
{

	int count = 0;
	int i = 0 ;
	int a = 0 ;
	double x = 0;
	double y = 0;
	int nextLine = 0;
	int number;
	map<int, Coordinates*> mymap_points;
	vector<Coordinates*> myvector_points;
	map<int, Couples*> mymap_couples;
	map<int, Couples*> mymap_collinear_couples;



	ifstream myfile;
	myfile.open("points.txt");


	while(!myfile.eof())
	{
		if( nextLine == 0)
		{
			myfile >> number ;
			nextLine++;
		}

		if( nextLine > 0)
			{

			myfile >> x;
			myfile >> y;
		
			Coordinates* point = new Coordinates(x,y); // CREATE AN OBJECT COORDINATES THAT HAS AS DATA X AND Y

			
			myvector_points.push_back(point);
			mymap_points[a] = point;
			
			a++;
			
		

		}

	}

	myfile.close();
	mymap_points.erase(a-1);

int z = 0 ;
while(true) /// Create couples with the points without a same couple twice AB but not BA
{
		for( int i = 0 ; i < myvector_points.size() ; i++)
		{

			for( int a = 0 ; a < myvector_points.size() ; a++)
				{
					if(myvector_points[i] != myvector_points[a])
						{
						Couples* new_couples = new Couples(myvector_points[i] , myvector_points[a]); // CREATE OBJECTS OF COUPLES AND PUSH INTO THE ORDERED MAP FOR MORE EFFICIENCY
						mymap_couples[z] = new_couples ;
						z++;

						if( a == (myvector_points.size() - 2) )
							break;
					}
				}

			break;
						
		}

		myvector_points.erase(myvector_points.begin()+0);

		if(myvector_points.size() == 2)
			break;
}









bool answer = true ;
int tracking = 0 ;
int c = 0 ;
int d = 0 ;
int test_col1 = 0 ;
map<int, Coordinates*> mymap_container;



	for( int i = 0 ; i < mymap_couples.size() ; i++)
	{
		
		if(mymap_collinear_couples.size() > 0)    // This if statement checks if the next couple to be used is not already collinear with an old couple so it doesn't repeat the same calculation
			{

			for( int h = 0 ; h < mymap_collinear_couples.size() ; h++)
				{
					if(collinear_couples(mymap_collinear_couples[h] , mymap_couples[i]) == true)
						{	
							test_col1 = 1 ;
							break;
						}
				}

				if(test_col1 == 1 )
					{
						test_col1 = 0 ;
						continue;
					}
			}

	

		for( int a = 0 ; a < mymap_points.size() ; a++) // Check each distinct couples with each point to check if it belongs to the line. and it doesn't check a point that is already in the couple to reduce runtime
			{
				
				if( (mymap_points[a] != mymap_couples[i]->point1)  && ( mymap_points[a] != mymap_couples[i]->point2) )
				{
				
				
					answer = mymap_couples[i]->equationTest(mymap_points[a]); // Check if  a point is collinear to the couples example C and AB
					
					if( answer == true) // INCREMENTS TRACKING EACH TIME IT FINDS A COLLINEAR POINT 
						{
							
						tracking++;
						mymap_container[c] = mymap_points[a];
						c++ ;
						}
						
					if(tracking >= 2 && a == (mymap_points.size() - 1)) // IF TRACKING >=2 AND IT IS THE END OF THE LOOP IT PRINTS THE SEQUENCE OF COLLINEAR POINTS
						{
							
							mymap_collinear_couples[d] = mymap_couples[i]; 
							d++ ;		
						
						mymap_couples[i]->print(); // PRINTS THE COUPLES
							
							

							for( int i = 0 ; i < mymap_container.size() ; i++) // PRINTS THE POINT COLLINEAR TO THE COUPLE
							{	
								mymap_container[i]->print();
							}

							cout<< endl ;

							
										
					}

			}

		}

				c = 0 ;
				mymap_container.clear();

						
tracking = 0 ;

	
}

return 0 ;

}



// 
