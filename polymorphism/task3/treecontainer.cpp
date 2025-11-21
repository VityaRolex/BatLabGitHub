

#include "treecontainer.h"
#include <fstream>
#include <sstream>


TreeContainer::~TreeContainer(){ for(auto p:arr) delete p; }


void TreeContainer::loadFromFile(const std::string& fn){
std::ifstream f(fn);
std::string line;
while(std::getline(f,line)){
std::stringstream ss(line);
std::string kind,name,types;
int age; double x,y;
ss>>kind>>name>>age>>types;
TreeType tt = (types=="leaf"?TreeType::LEAF:TreeType::CONIFER);
if(kind=="forest"){ ss>>x; arr.push_back(new ForestTree(name,age,tt,x)); }
else if(kind=="fruit"){ ss>>x>>y; arr.push_back(new FruitTree(name,age,tt,x,y)); }
}
}


void TreeContainer::printAll() const{ for(auto p:arr){ p->print(std::cout); std::cout<<"\n";} }


int TreeContainer::countByType(TreeType t) const{
int c=0; for(auto p:arr) if(p->getType()==t) c++; return c;
}
int TreeContainer::countForest() const{
int c=0; for(auto p:arr) if(p->isForest()) c++; return c;
}
int TreeContainer::countFruit() const{
int c=0; for(auto p:arr) if(p->isFruit()) c++; return c;
}


void TreeContainer::sortTrees(){
std::sort(arr.begin(),arr.end(),[](Tree* a, Tree* b){
if(a->getName()==b->getName()) return a->getAge()>b->getAge();
return a->getName()<b->getName();
});
}