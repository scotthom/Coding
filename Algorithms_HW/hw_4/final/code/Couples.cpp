#include "Couples.h"


	Couples::Couples(Coordinates* point1, Coordinates* point2)
	{
		this->point1 = point1;
		this->point2 = point2;

	}

	double Couples::slope()
	{
		double slp = 0 ;

		slp = (point1->y - point2->y)/(point1->x - point2->x);
		return slp;


	}

	void Couples::print()
	{

		cout << "(" << point1->x << "," << point1->y << ")" << endl;
		cout << "(" << point2->x << "," << point2->y << ")" << endl;
	}

	bool Couples::equationTest( Coordinates* point)
	{
		double slope1 = slope();

		double intercept = 0.0 ;

		if(isinf(slope1) == 1 )
		{
			if(point1->x == point->x)
				return true;
		}
		else if( slope1 == 0.0)
		{
			if(point1->y == point->y)
				return true;
		}
		else 
		{
			

			intercept = point1->y - (slope1 * point1->x);

			double result = point->y - (slope1*point->x) - intercept;

			if( result == 0.000000)
				return true ;
		}

		return false ;




	}



