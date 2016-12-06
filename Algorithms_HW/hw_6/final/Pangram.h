#ifndef PANGRAM_H
#define PANGRAM_H

#include  <iostream>
#include <vector>
#include <map>
using namespace std ;




class Pangram
{

	public :
	Pangram( int first, int end);
	void content();
	int size();
	int first;
	int end;
};


Pangram::Pangram(int first, int end)
{

	this->first = first;
	this->end = end;


}

void Pangram::content()
{

	cout << "start " << first << " end " << end << endl; ;

}

int Pangram::size()
{
	return (end - first);
}

extern vector<Pangram*> vec_pangram;

#endif


