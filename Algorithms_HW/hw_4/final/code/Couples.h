#ifndef COUPLES_H
#define COUPLES_H

#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include "Coordinates.h"

using namespace std ;

class Couples
{

	
	public :
	Couples(Coordinates* point1, Coordinates* point2);
	Coordinates* point1;
	Coordinates* point2;
	double slope();
	bool equationTest(Coordinates* point);
	void print();

} ;

#endif