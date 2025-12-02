#include"complex.h"


const Complex_Number* root(const Complex_Number& a, int deg)
{
    Complex_Number* res = new Complex_Number[deg];
    int counter{};
    double mod = std::pow(abs(a), 1.0/deg);
    double arg = Arg(a)/deg;
    double change = 2*M_PI/deg;
    while(counter < deg)
    {
        res[counter] = Complex_Number(mod*cos(arg + change*counter), mod*sin(arg + change*counter));
        ++counter;   
    }
    return res;
}
std::ostream& operator <<(std::ostream& out, const Complex_Number& a)
{
    if(a.rePart != 0 || a.imPart == 0)
    {
        out << a.rePart;
    }
    if(a.imPart > 0)
    {
        out << '+';
    }
    if(a.imPart != 0)
    {
        out << a.imPart << 'i';
    }
    return out;
}


const Complex_Number pow(const Complex_Number& z, int n)
{
    double arg = Arg(z)*n;
    double mod = std::pow(abs(z), n);
    return Complex_Number(mod*cos(arg), mod*sin(arg));
}

double Arg(const Complex_Number& z)
{
    return atan2(z.imPart, z.rePart);
}


double abs(const Complex_Number& a)
{
    return std::pow((a.imPart * a.imPart) + (a.rePart * a.rePart), 0.5);
}




Complex_Number operator /(const Complex_Number& a, const Complex_Number& b)
{
    return a * (~b);
}



Complex_Number operator -(const Complex_Number& x)
{
    return Complex_Number(-x.rePart, -x.imPart);
}


Complex_Number operator -(const Complex_Number& a, const Complex_Number& b)
{
    return a + (-b);
}

Complex_Number operator ~(const Complex_Number& x)
{
    if (x.imPart == 0 && x.rePart == 0)
    {
        throw std::runtime_error("division by zero");
    }
    double a = x.rePart;
    double b = x.imPart;
    double den = a*a + b*b;
    return Complex_Number(a/den, -b/den);
}

Complex_Number operator *(const Complex_Number& lhs, const Complex_Number& rhs)
{
    return Complex_Number(lhs.rePart * rhs.rePart - lhs.imPart * rhs.imPart, lhs.rePart * rhs.imPart + lhs.imPart * rhs.rePart);
}

Complex_Number operator +(const Complex_Number& lhs, const Complex_Number& rhs)
{
    return Complex_Number(lhs.rePart + rhs.rePart, lhs.imPart + rhs.imPart);
}

Complex_Number& Complex_Number::operator =(const Complex_Number& init)
{
    if(this != &init)
    {
        this->rePart = init.rePart;
        this->imPart = init.imPart;
    }
    return *this;
}