#include "IMT2019030_DirectMappedCache.h"

//Constructors and Destructors
DMCache::DMCache(){}
DMCache::DMCache(int CacheSize,int BlockSize,int AddressSize){
    this->CacheSize=CacheSize;
    this->BlockSize=BlockSize;
    this->AddressLength=AddressSize;
    this->init();
}
DMCache::~DMCache(){
    this->Cache.clear();
}
DMCache::DMCache(const DMCache&oldObj){
    this->CacheSize=oldObj.CacheSize;
    this->BlockSize=oldObj.BlockSize;
    this->NumberOfLines=oldObj.NumberOfLines;
    this->AddressLength=oldObj.AddressLength;
    this->IndexSize=oldObj.IndexSize;
    this->TagSize=oldObj.TagSize;
    this->DataSize=oldObj.DataSize;
    this->ByteOffset=oldObj.ByteOffset;
    this->Cache=oldObj.Cache;
}    

//Member functions
void DMCache::init(){
    this->ByteOffset=ceil(log2(this->BlockSize));
    this->NumberOfLines=this->CacheSize/this->BlockSize;
    this->IndexSize=ceil(log2(this->NumberOfLines));
    this->TagSize=this->AddressLength-(this->ByteOffset+this->IndexSize);
    this->DataSize=4*this->BlockSize;
    for(int i=0;i<this->NumberOfLines;i++){
        this->Cache.push_back(Block(this->BlockSize,this->DataSize));
    }
}

//Simply does the check for index and tag match
int DMCache::CheckAndHit(string HexAddress){
    HexAddress=HexAddress.substr(2,HexAddress.size()-1);
    Bitset BinAddress=Bitset::HexToBin(HexAddress);
    int index=Bitset::BinToDec(BinAddress.extract(this->ByteOffset,this->ByteOffset+this->IndexSize-1));
    Bitset tag=BinAddress.extract(this->ByteOffset+this->IndexSize,this->AddressLength-1);
    //If the valid bit is zero
    if(Cache[index].BValidBit().stringform()=="0"){
        Bitset validbit(1);
        validbit.setBitset("1");
        Cache[index].setValidBit(validbit);
        Cache[index].setTag(tag);
        return 0;
    }
    //If there is a tag match and index match
    if(Cache[index].BTag().stringform()==tag.stringform()){
        return 1;
    }
    //If the valid bit is one and there is no tag match
    Cache[index].setTag(tag);
    return 0;
}