#ifndef TREE_H
#define TREE_H
#include <string>
#include <iostream>


enum class TreeType { LEAF, CONIFER };


class Tree {
protected:
std::string name;
int age;
TreeType type;


public:
Tree(const std::string& n, int a, TreeType t) : name(n), age(a), type(t) {}
virtual ~Tree() = default;


const std::string& getName() const { return name; }
int getAge() const { return age; }
TreeType getType() const { return type; }


virtual bool isForest() const = 0;
virtual bool isFruit() const = 0;


virtual void print(std::ostream&) const = 0;
};
#endif