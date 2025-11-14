#ifndef COMPLEX_H
#define COMPLEX_H

#define M_PI       3.14159265358979323846
#include<iostream>
#include<cmath>

class Complex_Number
{
    double rePart;
    double imPart;
    
public:
    Complex_Number(const double intP = 0, const double imP = 0)
    {
        this->rePart = intP;
        this->imPart = imP;
    }
    Complex_Number(const Complex_Number& init)
    {
        this->rePart = init.rePart;
        this->imPart = init.imPart;
    }
    ~Complex_Number()
    {
        //do smth
    }
    
    friend std::ostream& operator <<(std::ostream& out, const Complex_Number& a);
    Complex_Number& operator =(const Complex_Number& init);
    friend Complex_Number operator +(const Complex_Number& lhs, const Complex_Number& rhs);
    friend Complex_Number operator *(const Complex_Number& lhs, const Complex_Number& rhs);
    friend Complex_Number operator ~(const Complex_Number& x);
    friend Complex_Number operator -(const Complex_Number&);
    friend Complex_Number operator -(const Complex_Number&, const Complex_Number&);
    friend Complex_Number operator /(const Complex_Number&, const Complex_Number&);
    friend double abs(const Complex_Number&);
    friend double Arg(const Complex_Number& z);
    friend const Complex_Number pow(const Complex_Number& z, int deg);
    friend const Complex_Number* root(const Complex_Number& a, int deg);
    friend Complex_Number operator +(const double& lhs, const Complex_Number& rhs);
};


#endif