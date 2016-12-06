#include "Coordinates.h"

Coordinates::Coordinates(double coordinates1, double coordinates2)
{

this->x = coordinates1;
this->y = coordinates2;

}

void Coordinates::print()
{
cout<< "(" << this->x << "," << this->y << ")" << endl;
}

