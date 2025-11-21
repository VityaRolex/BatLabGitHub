#ifndef FORESTTREE_H
#define FORESTTREE_H
#include "tree.h"


class ForestTree : public Tree {
double woodAmount; // amount of wood
public:
ForestTree(const std::string&, int, TreeType, double);
void print(std::ostream&) const override;
bool isForest() const override { return true; }
bool isFruit() const override { return false; }
};
#endif