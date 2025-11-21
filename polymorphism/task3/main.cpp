#include "treecontainer.h"
#include <iostream>


int main(){
TreeContainer tc;
tc.loadFromFile("trees.txt");


std::cout<<"\nAll trees:\n";
tc.printAll();


tc.sortTrees();
std::cout<<"\nSorted trees:\n";
tc.printAll();


std::cout<<"Leaf: "<<tc.countByType(TreeType::LEAF);
std::cout<<"\nConifer: "<<tc.countByType(TreeType::CONIFER);


std::cout<<"\nForest: "<<tc.countForest();
std::cout<<"\nFruit: "<<tc.countFruit()<<"\n";
}