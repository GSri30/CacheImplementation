#include "IMT2019030_Set.h"

//Constructors
Set::Set(){}
Set::Set(int NumOfWays,int tagsize,int datasize){
    for(int i=0;i<NumOfWays;i++){
        this->set.push_back(Block(tagsize,datasize));
    }
}
Set::~Set(){
    this->set.clear();
}
Set::Set(const Set&oldObj){
    this->set.clear();
    this->set=oldObj.getset();
}

//Getters
vector<Block> Set::getset()const{
    return this->set;
}
int Set::getSize()const{
    return this->set.size();
}
