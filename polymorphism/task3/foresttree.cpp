#include "foresttree.h"
#include <iostream>


ForestTree::ForestTree(const std::string& n, int a, TreeType t, double w)
: Tree(n,a,t), woodAmount(w) {}


void ForestTree::print(std::ostream& os) const {
os << "ForestTree: " << name << " age=" << age
<< " type=" << (type==TreeType::LEAF?"leaf":"conifer")
<< " wood=" << woodAmount;
}