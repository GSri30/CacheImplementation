#ifndef SACACHE_H_
#define SACACHE_H_

#include "IMT2019030_Set.h"
#include<cmath>
#include<list>

class SACache{
    //Class attributes
    private:
        int CacheSize,BlockSize,NumberOfSets,NumberOfWays,AddressLength,IndexSize,TagSize,DataSize,ByteOffset;
        //Array of Sets
        //Where a set is an array of Blocks. (4 blocks)
        vector<Set>Cache;
        //Array used for LRU algorithm
        vector<list<int>>LRUhelper;

    //Constructors and Destructors
    public:
        SACache();
        SACache(int ,int ,int ,int =32);
        ~SACache();
        SACache(const SACache&);

    //Member function to initialise the cache
    public:
        void init();

    //Main function used to store data inside the cache
    //Returns 1 if its a hit, otherwise returns 0
    public:
        int CheckAndHit(string);
};

#endif