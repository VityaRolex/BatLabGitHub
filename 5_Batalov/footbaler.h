#ifndef FOOTBALER_H
#define FOOTBALER_H


#include<iostream>
#include<cstring>
static int next_id = 0;

char* copyStringToNewPlace(char* str)
{
    if(str == nullptr)
    {
        return nullptr;
    }
    char* newStr = new char[strlen(str)+1];
    strcpy(newStr, str);
    return newStr;
}

const enum Spec{Vratar, Zachitnik, demi_Zachitnik, Attacker, SAVE};
class Footbaler{
private:
    
    const int id;
    char* surname;
    
    const Spec spec;
    int contract_ending_age;
public:
    Footbaler(char* name = nullptr, Spec spec = Spec::SAVE, int ending = 0): id(next_id++), spec(spec), surname(copyStringToNewPlace(name)), contract_ending_age(ending){}
    Footbaler(const Footbaler& rhs): id(next_id++), spec(spec), surname(copyStringToNewPlace(rhs.surname)), contract_ending_age(rhs.contract_ending_age){}
    Footbaler(Footbaler&& rhs): id(rhs.id), spec(spec), surname(rhs.surname), contract_ending_age(rhs.contract_ending_age)
    {
        *(const_cast<int*>(&rhs.id)) = 0;
        rhs.surname = nullptr;
        rhs.contract_ending_age = 0;
    }
    Footbaler& operator = (const Footbaler& rhs)
    {
        if(this != &rhs)
        {
            surname = copyStringToNewPlace(rhs.surname);
            contract_ending_age = rhs.contract_ending_age;
            *(const_cast<Spec*>(&spec)) = rhs.spec;
        }
        return *this;
    }
    Footbaler& operator = (Footbaler&& rhs)
    {
        if(this != &rhs)
        {
            surname = rhs.surname;
            contract_ending_age = rhs.contract_ending_age;
            *(const_cast<int*>(&id)) = rhs.id;
            *(const_cast<Spec*>(&spec)) = rhs.spec;
            *(const_cast<int*>(&rhs.id)) = 0;
            rhs.surname = nullptr;
            *(const_cast<Spec*>(&rhs.spec)) = SAVE;
            rhs.contract_ending_age = 0;
        }
        return *this;
    }
    virtual ~Footbaler() = default;
    const char* getSurname()
    {
        return copyStringToNewPlace(surname);
    }
    const int getEndigDate()
    {
        return contract_ending_age;
    }
    const int getId()
    {
        return id;
    }
    const Spec getSpec()
    {
        return spec;
    }
    void setSurname(char* str)
    {
        delete [] surname;
        surname = copyStringToNewPlace(str);
    }
    void setEndingDate(int date)
    {
        contract_ending_age = date;
    }
    
};
    bool isSameSpec(Footbaler& lhs, Footbaler& rhs)
    {
        return lhs.getSpec() == rhs.getSpec();
    }
    std::ostream& operator << (std::ostream& out, Footbaler& obj)
    {
        out << "Surname -" << obj.getSurname() << " | id - " << obj.getId() << " | contract ending is in " << obj.getEndigDate() << "th year | specialization is - ";
        switch(obj.getSpec())
        {
            case Spec::Vratar:{
                out << "Goalkeeper";
                break;
            } 
            case Spec::Attacker:{
                out << "Attacker";
                break;
            }
            case Spec::Zachitnik:{
                out << "Saver";
                break;
            }
            case Spec::demi_Zachitnik:{
                out << "half-Saver";
                break;
            }
            default:
            {
                break;
            }
        }
    }

#endif;