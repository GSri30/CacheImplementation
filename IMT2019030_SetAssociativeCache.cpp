#include "IMT2019030_SetAssociativeCache.h"


//Consturctos and destructors
SACache::SACache(){}
SACache::SACache(int CacheSize,int NumberOfWays,int BlockSize,int AddressSize){
    this->CacheSize=CacheSize;
    this->NumberOfWays=NumberOfWays;
    this->BlockSize=BlockSize;
    this->AddressLength=AddressSize;
    this->init();
}
SACache::~SACache(){
    this->Cache.clear();
}
SACache::SACache(const SACache&oldObj){
    this->CacheSize=oldObj.CacheSize;
    this->NumberOfWays=oldObj.NumberOfWays;
    this->BlockSize=oldObj.BlockSize;
    this->NumberOfSets=oldObj.NumberOfSets;
    this->AddressLength=oldObj.AddressLength;
    this->IndexSize=oldObj.IndexSize;
    this->TagSize=oldObj.TagSize;
    this->DataSize=oldObj.DataSize;
    this->ByteOffset=oldObj.ByteOffset;
    this->Cache=oldObj.Cache;
}


//Member functions
void SACache::init(){
    this->ByteOffset=ceil(log2(this->BlockSize));
    this->NumberOfSets=this->CacheSize/(this->BlockSize*this->NumberOfWays);
    this->IndexSize=ceil(log2(this->NumberOfSets));
    this->TagSize=this->AddressLength-(this->ByteOffset+this->IndexSize);
    this->DataSize=4*this->BlockSize;
    for(int i=0;i<this->NumberOfSets;i++){
        this->Cache.push_back(Set(this->NumberOfWays,this->TagSize,this->DataSize));
        this->LRUhelper.push_back(list<int>());
    }
}

int SACache::CheckAndHit(string HexAddress){
    HexAddress=HexAddress.substr(2,HexAddress.size()-1);
    Bitset BinAddress=Bitset::HexToBin(HexAddress);
    int index=Bitset::BinToDec(BinAddress.extract(this->ByteOffset,this->ByteOffset+this->IndexSize-1));
    Bitset tag=BinAddress.extract(this->ByteOffset+this->IndexSize,this->AddressLength-1);
    
    //LRU algorithm
    //Here I use an array (storing the 4 ways in the order they have been used frequently) which acts as a "Queue". i.e. the element that enters first, leaves first.
    //The left most way is most frequently used way.
    //The right most way is the least frequently used way.
    //When there is a hit at any particular moment, I remove that particular way, and again insert in front of the array.

    for(int i=0;i<Cache[index].getSize();i++){
        //When the valid bit is set for current way and there is a tag match and also have same index
        if(Cache[index].set[i].BValidBit().stringform()=="1" and Cache[index].getset()[i].BTag().stringform()==tag.stringform()){
            LRUhelper[index].remove(i);
            LRUhelper[index].push_front(i);
            return 1;
        }
        //When the valid bit itself is not set
        if(Cache[index].getset()[i].BValidBit().stringform()=="0"){
            Bitset validbit(1);
            validbit.setBitset("1");
            Cache[index].set[i].setValidBit(validbit);
            Cache[index].set[i].setTag(tag);
            this->LRUhelper[index].push_front(i);
            return 0;
        }
    }
    //When the valid bit is set for all the ways but there is no tag match with any of the way
    int way=LRUhelper[index].back();
    LRUhelper[index].pop_back();
    LRUhelper[index].push_front(way);
    Cache[index].set[way].setTag(tag);
    return 0;
}