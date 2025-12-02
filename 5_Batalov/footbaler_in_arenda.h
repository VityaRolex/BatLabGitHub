#ifndef FOOTBALER_IN_ARENDA_H
#define FOOTBALER_IN_ARENDA_H

#include "footbaler.h"
class Footbaler_in_Arenda: public Footbaler{
private:
    int clubCount;
public:
    Footbaler_in_Arenda(char* name = nullptr, Spec spec = Spec::SAVE, int ending = 0, int clubs = 0): Footbaler(name, spec, ending), clubCount(clubs){}
    Footbaler_in_Arenda(const Footbaler_in_Arenda& rhs): Footbaler(rhs), clubCount(rhs.clubCount){}
    Footbaler_in_Arenda(Footbaler_in_Arenda&& rhs): Footbaler(rhs), clubCount(rhs.clubCount){rhs.clubCount = 0;}
    virtual ~Footbaler_in_Arenda() = default;
    Footbaler_in_Arenda& operator=(const Footbaler_in_Arenda& other) = delete;
    Footbaler_in_Arenda& operator=(const Footbaler_in_Arenda& other){
        if(this != &other)
        {
            ((Footbaler)(*this)) = ((Footbaler)other);
            clubCount = other.clubCount;
        }
        return *this;
    }
    const int getClubCount()
    {
        return clubCount;
    }
    void setClubCount(const int clubs)
    {
        clubCount = clubs;
    }
};
std::ostream& operator << (std::ostream& out, Footbaler_in_Arenda& obj)
{
    out << (Footbaler&)obj << " | club count - " << obj.getClubCount();
}


#endif