#ifndef BITSET_H_
#define BITSET_H_

#include<string>
#include<map>
using namespace std;

//Basic unit
//Used to store the bits
//Stores in form of a string
class Bitset{
    //Class attributes
    private:
        string bitset;

    //Constructors and Destructors
    public:
        Bitset();
        Bitset(string);
        Bitset(int);
        Bitset(const Bitset&);
        ~Bitset();
    
    //Getters and Setters
    public:
        int size();
        void setBitset(string);
        string stringform();

    //Member functions
    public:
        //Used to extract some given range of bits
        Bitset extract(int,int);
        //Used to extract some given range of bits and returns its string form
        string extractString(int,int);
        //static Function to convert an Hex number to a binary
        static Bitset HexToBin(string);
        //static Function to convert an Binary number to a Decimal
        static int BinToDec(Bitset);
};

#endif