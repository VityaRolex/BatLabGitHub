#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class Equation{
public:
	virtual void solve() = 0;
	virtual void print() = 0;
};



#endif