#include "LinearEquation.h"

LineralEquation::LineralEquation(double a, double b): a(a), b(b){}

LineralEquation::LineralEquation(const LineralEquation& other): a(other.a), b(other.b) {}

LineralEquation::LineralEquation(LineralEquation&& other) noexcept: a(other.a), b(other.b) {
	other.a = 0;
	other.b = 0;
}

LineralEquation& LineralEquation::operator=(const LineralEquation& other) {
	a = other.a;
	b = other.b;
	return *this;
}

LineralEquation& LineralEquation::operator=(LineralEquation&& other) noexcept {
	a = other.a;
	b = other.b;
	other.a = 0;
	other.b = 0;
	return *this;
}

void LineralEquation::LineralEquation::solve(){
	std::cout << " Корень: ";
	if(a != 0) std::cout << (-b)/a << "\n";
	else if(b == 0) std::cout << "бесконечно много решений.\n";
	else std::cout << "решений нет.\n";
}

void LineralEquation::LineralEquation::print(){
	if(a != 0) std::cout << a << "x";
	if(b != 0) {
		char s = b>0 ? '+' : '-';
		std::cout << " " << s << " " << abs(b);
	}
}

double LineralEquation::getA(){
	return a;
}

double LineralEquation::getB(){
	return b;
}