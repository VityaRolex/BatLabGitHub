#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include "equation.h"

class QuadraticEquation: public Equation {
private:
	double a;
	double b;
	double c;
public:
	QuadraticEquation(double a = 1, double b = 0, double c = 0);
	QuadraticEquation(const QuadraticEquation&);
	QuadraticEquation(QuadraticEquation&&) noexcept;
	~QuadraticEquation() = default;
	QuadraticEquation& operator=(const QuadraticEquation&);
	QuadraticEquation& operator=(QuadraticEquation&&) noexcept;
	double disc();
	void solve() override;
	void print() override;
	double getA();
};


#endif