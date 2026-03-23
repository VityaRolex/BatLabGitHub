#ifndef MUSIC_H
#define MUSIC_H


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

const enum Genre{Sing, Opera, Symphony, Other};
class Music{
private:
    
    const int id;
    char* name;
    
    const Genre genre;
    int contract_ending_age;
public:
    Music(char* name = nullptr, Genre genre = Genre::Other, int ending = 0): id(next_id++), genre(genre), name(copyStringToNewPlace(name)), contract_ending_age(ending){}
    Music(const Music& rhs): id(next_id++), genre(genre), name(copyStringToNewPlace(rhs.name)), contract_ending_age(rhs.contract_ending_age){}
    Music(Music&& rhs): id(rhs.id), genre(genre), name(rhs.name), contract_ending_age(rhs.contract_ending_age)
    {
        *(const_cast<int*>(&rhs.id)) = 0;
        rhs.name = nullptr;
        rhs.contract_ending_age = 0;
    }
    Music& operator = (const Music& rhs)
    {
        if(this != &rhs)
        {
            name = copyStringToNewPlace(rhs.name);
            contract_ending_age = rhs.contract_ending_age;
            *(const_cast<Genre*>(&genre)) = rhs.genre;
        }
        return *this;
    }
    Music& operator = (Music&& rhs)
    {
        if(this != &rhs)
        {
            name = rhs.name;
            contract_ending_age = rhs.contract_ending_age;
            *(const_cast<int*>(&id)) = rhs.id;
            *(const_cast<Genre*>(&genre)) = rhs.genre;
            *(const_cast<int*>(&rhs.id)) = 0;
            rhs.name = nullptr;
            *(const_cast<Genre*>(&rhs.genre)) = Other;
            rhs.contract_ending_age = 0;
        }
        return *this;
    }
    virtual ~Music() = default;
    const char* getSurname()
    {
        return copyStringToNewPlace(name);
    }
    const int getEndigDate()
    {
        return contract_ending_age;
    }
    const int getId()
    {
        return id;
    }
    const Genre getSpec()
    {
        return genre;
    }
    void setSurname(char* str)
    {
        delete [] name;
        name = copyStringToNewPlace(str);
    }
    void setEndingDate(int date)
    {
        contract_ending_age = date;
    }
    
};
    bool isSameSpec(Music& lhs, Music& rhs)
    {
        return lhs.getSpec() == rhs.getSpec();
    }
    std::ostream& operator << (std::ostream& out, Music& obj)
    {
        out << "Surname -" << obj.getSurname() << " | id - " << obj.getId() << " | contract ending is in " << obj.getEndigDate() << "th year | specialization is - ";
        switch(obj.getSpec())
        {
            case Genre::Vratar:{
                out << "Goalkeeper";
                break;
            } 
            case Genre::Attacker:{
                out << "Attacker";
                break;
            }
            case Genre::Zachitnik:{
                out << "Saver";
                break;
            }
            case Genre::demi_Zachitnik:{
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