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
        uint64_t GCD = std::gcd(num, denom);
        neg /= GCD;
        num /= GCD;
        denom /= GCD;
        checkDenom();
    }
    void checkDenom()
    {
        if(!denom)
        {
            throw std::runtime_error("Деление на ноль");
        }
    }
    Fraction makeRevFrac(const Fraction& frac)
    {
        Fraction res(frac.denom, frac.num, frac.neg);
        res.simplify();
        return res;
    }
public:
    Fraction(uint64_t nom = 0, uint64_t denum = 1, bool nego = 0)
    {
        num = nom;
        denom = denum;
        neg = nego;
        simplify();
    }
    friend Fraction operator +(const Fraction& a, const Fraction& b);
    friend Fraction operator *(const Fraction& a, const Fraction& b);
    friend Fraction operator /(const Fraction& a, const Fraction& b);
    friend Fraction operator -(const Fraction& a, const Fraction& b);
    friend Fraction minFrac(const Fraction& a, const Fraction& b);
    friend std::ostream& operator <<(std::ostream& out, Fraction a);
};



std::ostream& operator <<(std::ostream& out, Fraction a)
{
    char sign{a.neg == true ? '-' : ' '};
    std::cout << sign << a.num << '/' << a.denom;
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
    Fraction f(a.num*b.num, a.denom*b.denom, a.neg == b.neg ? 0:1);
    f.simplify();
    return f;
}


Fraction operator /(const Fraction& a, const Fraction& b)
{
    return a * Fraction().makeRevFrac(b);
}


Fraction operator +(const Fraction& a, const Fraction& b)
{
    int t1 = a.num*b.denom;
    int t2 = a.denom*b.num;
    bool swapped{};
    if (a.neg != b.neg && t1 < t2)
    {
        std::swap(t1,t2);
        swapped = true;
    }
    Fraction f{t1 + (t2*(a.neg == b.neg ? 1 : -1)), a.denom*b.denom, a.neg^swapped};
    f.simplify();
    return f;
}


Fraction operator -(const Fraction& a, const Fraction& b)
{
    Fraction tmp(b.num, b.denom, !b.neg);
    return a + tmp;
}




int main()
{
    Fraction f2(1,2, 0);
    Fraction f1(1,3,0);
    Fraction res;
    try
    {
        res = f1/f2;
        std::cout << res;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}