#include<iostream>
#include<cstdint>
#include<numeric>
#include<exception>
class Fraction
{
    uint64_t num{0};
    uint64_t denom{1};
    bool neg{false};
    void simplify()
    {
        checkDenom();
        uint64_t GCD = std::gcd(num, denom);
        neg /= GCD;
        num /= GCD;
        denom /= GCD;
    }
    void checkDenom()
    {
        if(!denom)
        {
            throw std::runtime_error("Деление на ноль");
        }
    }
public:
    Fraction(uint64_t nom = 0, uint64_t denum = 1, bool nego = 0)
    {
        num = nom;
        denom = denum;
        neg = nego;
        simplify();
        if(num == 0)
        {
            denom = 1;
            neg = false;
        }
    }
    Fraction& Fraction::operator =(const Fraction& rhs)
    {
        if(this != &rhs)
        {
            this->num = rhs.num;
            this->denom = rhs.denom;
            this->neg = rhs.neg;
        }
        return *this;
    }
    
    friend Fraction operator +(const Fraction& a, const Fraction& b);
    friend Fraction operator *(const Fraction& a, const Fraction& b);
    friend Fraction operator /(const Fraction& a, const Fraction& b);
    friend Fraction operator -(const Fraction& a, const Fraction& b);
    friend Fraction minFrac(const Fraction& a, const Fraction& b);
    friend std::ostream& operator <<(std::ostream& out, const Fraction& a);
    friend Fraction operator ~(const Fraction& a);
    friend Fraction operator -(const Fraction& a);
    Fraction operator ++()
    {
        *this = *this + Fraction(1,1,0);
        return *this;
    };
    Fraction operator --()
    {
        *this = *this + Fraction(1,1,1);
        return *this;
    }
    Fraction operator ++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    };
    Fraction operator --(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    };
    bool operator ==(const Fraction& second)
    {
        return this->num == second.num && this->denom == second.denom && this->neg == second.neg;
    }
    bool operator <(const Fraction& second)
    {
        return minFrac(*this, second) == *this;
    }
};


Fraction operator -(const Fraction& a)
{
    return Fraction(a.num, a.denom, !a.neg);
}


Fraction operator ~(const Fraction& a)
{
    return Fraction(a.denom, a.num, a.neg);
}


std::ostream& operator <<(std::ostream& out, const Fraction& a)
{
    char sign{};
    if(a.neg)
    {
        sign = '-';
    }
    std::cout << sign << a.num;
    if (a.denom != 1)
    {
        std::cout << '/' << a.denom;
    }
    return out;
}


Fraction minFrac(const Fraction& a, const Fraction& b)
{
    int flag{};
    Fraction arr[]{a,b};
    if(a.num*b.denom < a.denom*b.num)
    {
        flag = 1;
    }
    if(!arr[flag].neg)
    {
        flag = (flag + 1)%2;
    }
    return arr[flag];
}


Fraction operator *(const Fraction&a, const Fraction& b)
{
    return Fraction(a.num * b.num, a.denom * b.denom, a.neg != b.neg);
}


Fraction operator /(const Fraction& a, const Fraction& b)
{
    return a * (~b);
}


Fraction operator +(const Fraction& a, const Fraction& b)
{
    int t1 = a.num * b.denom;
    int t2 = a.denom * b.num;
    bool swapped{};
    if (a.neg != b.neg && t1 < t2)
    {
        std::swap(t1,t2);
        swapped = true;
    }
    return Fraction(t1 + (t2 * (a.neg == b.neg ? 1 : -1)), a.denom*b.denom, a.neg ^ swapped);
}


Fraction operator -(const Fraction& a, const Fraction& b)
{
    return a + (-b);
}


int main()
{

    int a[5]{0,1,2,3,4};
    //std::cout << 2[a];
    Fraction f2(1,2, 0);
    Fraction f1(1,3,0);
    Fraction res;
    try
    {
        res = ++(f1++++++);
        std::cout << res << f1;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}