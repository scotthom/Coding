#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std ;

class Coordinates
{

	
	public :
	Coordinates(double coordinates1, double coordinates2);
	
	void print();
	double x;
	double y;

} ;

#endif