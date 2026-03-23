#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <limits>
#include <string>
#include <algorithm>
#include<cctype>

void inputVector(std::vector<int>&, std::istream&);
void clearInput(std::istream&);
int countSum(std::vector<int>&);
size_t countNumsEqualTo(std::vector<int>&, int n);
int countAverage(std::vector<int>&);
void changeZerosToAverage(std::vector<int>&);
int countSumFromAToB(std::vector<int>&, size_t, size_t);
void addToEveryElementOfVectorSumOfVectorFromAToB(std::vector<int>&, size_t, size_t);
void changeEvenToMaxMinusMin(std::vector<int>&);
void deleteAllEqualOnModuleSaufFirst(std::vector<int>&);
void task2(std::vector<int>&);


void openStream(std::ifstream&, const char*);
void readStringsFromFile(std::vector<std::string>&, std::ifstream&);
void sortVector(std::vector<std::string>&);
void printVector(std::vector<std::string>&);
void printOnLetter(std::vector<std::string>&, char);
void deleteOnLetter(std::vector<std::string>&, char);
void task3(std::vector<std::string>&);


struct Time{
    int hours;
    int minutes;
};

void optimizeTime(Time&);


bool operator <(Time&, Time&);
bool operator ==(Time&, Time&);
bool operator <=(Time&, Time&);
bool operator !=(Time&, Time&);
std::istream& operator >> (std::istream&, Time&);
std::ostream& operator << (std::ostream&, Time&);



enum Type{Passenger, Fast};

struct Train{
    uint number;
    std::string end;
    Type type;
    Time starting_time;
    int in_road_time;

};

std::ostream& operator << (std::ostream&, Train&);
std::istream& operator >> (std::istream&, Train&);
void inputFromFile(std::vector<Train>&, std::ifstream&);
void sortByStartTime(std::vector<Train>&);
void outputTrainBehingTimes(std::vector<Train>&, Time&, Time&);
void outputTrainsInSameEnd(std::vector<Train>&, std::string&);
void outputFastTrainsInSameEnd(std::vector<Train>&, std::string&);
Train& searchFastestTrainInCertainEnd(std::vector<Train>&, std::string&);
#endif