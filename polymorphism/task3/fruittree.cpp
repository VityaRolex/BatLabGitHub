#include "fruittree.h"
#include <iostream>


FruitTree::FruitTree(const std::string& n, int a, TreeType t, double h, double st)
: Tree(n,a,t), harvestMass(h), storageTime(st) {}


void FruitTree::print(std::ostream& os) const {
os << "FruitTree: " << name << " age=" << age
<< " type=" << (type==TreeType::LEAF?"leaf":"conifer")
<< " harvest=" << harvestMass
<< " storage=" << storageTime;
}