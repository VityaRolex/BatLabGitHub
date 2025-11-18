#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H

#include "equation.h"

class LineralEquation: public Equation{
private:
	double a;
	double b;
public:
	LineralEquation(double a = 1, double b = 0);
	LineralEquation(const LineralEquation&);
	LineralEquation(LineralEquation&&) noexcept;
	~LineralEquation() = default;
	LineralEquation& operator=(const LineralEquation&);
	LineralEquation& operator=(LineralEquation&&) noexcept;
	void solve() override;
	void print() override;
	double getA();
	double getB();
};


#endif