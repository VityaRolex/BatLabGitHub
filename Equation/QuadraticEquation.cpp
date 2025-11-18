#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(double _a, double _b, double _c): a(_a), b(_b), c(_c){
	if(a == 0){
		throw std::invalid_argument("Это не линейное уравнение!");
	}
}

QuadraticEquation::QuadraticEquation(const QuadraticEquation& other): a(other.a), b(other.b), c(other.c) {}

QuadraticEquation::QuadraticEquation(QuadraticEquation&& other) noexcept: a(other.a), b(other.b), c(other.c) {
	other.a = 0;
	other.b = 0;
	other.c = 0;
}

QuadraticEquation& QuadraticEquation::operator=(const QuadraticEquation& other) {
	a = other.a;
	b = other.b;
	c = other.c;
	return *this;
}

QuadraticEquation& QuadraticEquation::operator=(QuadraticEquation&& other) noexcept {
	a = other.a;
	b = other.b;
	c = other.c;
	other.a = 0;
	other.b = 0;
	other.c = 0;
	return *this;
}

void QuadraticEquation::QuadraticEquation::print(){
	if(a != 0) std::cout << a << "x^2";
	if(b != 0) {
		char s = b>0 ? '+' : '-';
		std::cout << " " << s << " " << abs(b) << "x";
	}
	if(c != 0) {
		char v = c>0 ? '+' : '-';
		std::cout << " " << v << " " << abs(c);
	}
}

double QuadraticEquation::QuadraticEquation::disc(){
	return (b*b - 4*a*c);
}

void QuadraticEquation::QuadraticEquation::solve(){
	double d = disc();
	std::cout << " Корни: ";
	if (d > 0) {
		double x1 = (-b + std::sqrt(d)) / (2*a);
		double x2 = (-b - std::sqrt(d)) / (2*a);
		std::cout << "x1 = " << x1 << "; ";
		std::cout << "x2 = " << x2 << "\n";
	}
	else if (d == 0) {
		double x = -b / (2*a);
		std::cout << "x = " << x << "\n";
	}
	else std::cout << "нет вещественных решений.\n";
}

double QuadraticEquation::getA(){
	return a;
}