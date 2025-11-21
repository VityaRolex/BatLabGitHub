#ifndef FRUITTREE_H
#define FRUITTREE_H
#include "tree.h"


class FruitTree : public Tree {
double harvestMass;
double storageTime;
public:
FruitTree(const std::string&, int, TreeType, double, double);
void print(std::ostream&) const override;
bool isForest() const override { return false; }
bool isFruit() const override { return true; }
};
#endif