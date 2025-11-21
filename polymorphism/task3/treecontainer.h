#ifndef TREECONTAINER_H
#define TREECONTAINER_H
#include <vector>
#include <algorithm>
#include "tree.h"
#include "foresttree.h"
#include "fruittree.h"


class TreeContainer {
std::vector<Tree*> arr;
public:
~TreeContainer();
void loadFromFile(const std::string&);
void printAll() const;
int countByType(TreeType) const;
int countForest() const;
int countFruit() const;
void sortTrees();
};
#endif