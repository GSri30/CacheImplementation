#ifndef DIRECTMAPPEDCACHE_H_
#define DIRECTMAPPEDCACHE_H_

#include "IMT2019030_Block.h"
#include<vector>
#include<cmath>

class DMCache{

    //Class attributes
    private:
        int CacheSize,BlockSize,NumberOfLines,AddressLength,IndexSize,TagSize,DataSize,ByteOffset;
        //Array of Blocks
        vector<Block>Cache;
    
    //Constructors and Destructors
    public:
        DMCache();
        DMCache(int ,int ,int =32);
        ~DMCache();
        DMCache(const DMCache&);

    //Member function to initialise the DM cache
    public:
        void init();

    //Member function which actually performs the function of a cache
    //It takes in hex address
    //Returns 1 if its a hit, 0 if its a miss
    public:
        int CheckAndHit(string);
};

#endif