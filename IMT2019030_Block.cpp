#include "IMT2019030_Block.h"

//Constructors
Block::Block(){}
Block::Block(int tag,int data){
    Bitset v(1);
    Bitset t(tag);
    Bitset d(data);
    this->ValidBit=v;
    this->Tag=t;
    this->Data=d;
}
Block::Block(Bitset tag,Bitset data){
    Bitset v(1);
    this->ValidBit=v;
    this->Tag=tag;
    this->Data=data;
}
Block::~Block(){}
Block::Block(const Block&oldObj){
    this->ValidBit=oldObj.ValidBit;
    this->Tag=oldObj.Tag;
    this->Data=oldObj.Data;
}


//Getters and Setters
Bitset Block::BValidBit(){
    return this->ValidBit;
}
Bitset Block::BTag(){
    return this->Tag;
}
Bitset Block::BData(){
    return this->Data;
}

void Block::setValidBit(Bitset validBit){
    this->ValidBit=validBit;
}
void Block::setTag(Bitset tag){
    this->Tag=tag;
}
void Block::setData(Bitset data){
    this->Data=data;
}

int Block::TagSize(){
    return this->Tag.size();
}
int Block::DataSize(){
    return this->Data.size();
}