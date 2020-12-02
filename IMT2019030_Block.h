#ifndef BLOCK_H_
#define BLOCK_H_

#include "IMT2019030_Bitset.h"

//Here "Index" is NOT an attribute of a block as there might be multiple blocks with same index and its implemented inside the cache
class Block{
    //Class attributes
    private:
        Bitset ValidBit,Tag,Data;

    //Constructors and Destructors
    public:
        Block();
        Block(int,int);
        Block(Bitset,Bitset);
        ~Block();
        Block(const Block&);
    
    //Getters and Setters
    public:
        Bitset BValidBit();
        Bitset BTag();
        Bitset BData();
        void setValidBit(Bitset);
        void setTag(Bitset);
        void setData(Bitset);

    //Getters
    public:
        int TagSize();
        int DataSize();
};

#endif