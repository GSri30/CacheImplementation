#ifndef SET_H_
#define SET_H_

#include<vector>
#include "IMT2019030_Block.h"
using namespace std;

//Array of 4 Blocks
class Set{
    //Class attributes
    public:
        vector<Block>set;
    
    //Constructors and Destructors
    public:
        Set();
        Set(int,int,int);
        ~Set();
        Set(const Set&);
    
    //Getters
    public:
        vector<Block>getset()const;
        int getSize()const;
};

#endif