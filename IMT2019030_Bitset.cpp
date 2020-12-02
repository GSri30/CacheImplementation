#include "IMT2019030_Bitset.h"

//Constructors and Destructors
Bitset::Bitset(){}
Bitset::Bitset(string bits){
    this->bitset=bits;
}
Bitset::Bitset(int size){
    string s(size,'0');
    this->bitset=s;
}
Bitset::Bitset(const Bitset&oldObj){
    this->bitset.clear();
    this->bitset=oldObj.bitset;
}
Bitset::~Bitset(){
    this->bitset.clear();
}

//Getters and Setters
int Bitset::size(){
    return this->bitset.size();
}
void Bitset::setBitset(string newBitset){
    this->bitset=newBitset;
}
string Bitset::stringform(){
    return this->bitset;
}


//Member functions
Bitset Bitset::extract(int leastSign,int mostSign){
    Bitset b(this->bitset.substr(this->bitset.size()-1-mostSign,mostSign-leastSign+1));
    return b;
}
string Bitset::extractString(int leastSign,int mostSign){
    return this->bitset.substr(this->bitset.size()-1-mostSign,mostSign-leastSign+1);
}

Bitset Bitset::HexToBin(string Hex){
    map<char,string>HexToBinHelper;
    HexToBinHelper.insert(pair<char,string>('0',"0000"));
    HexToBinHelper.insert(pair<char,string>('1',"0001"));
    HexToBinHelper.insert(pair<char,string>('2',"0010"));
    HexToBinHelper.insert(pair<char,string>('3',"0011"));
    HexToBinHelper.insert(pair<char,string>('4',"0100"));
    HexToBinHelper.insert(pair<char,string>('5',"0101"));
    HexToBinHelper.insert(pair<char,string>('6',"0110"));
    HexToBinHelper.insert(pair<char,string>('7',"0111"));
    HexToBinHelper.insert(pair<char,string>('8',"1000"));
    HexToBinHelper.insert(pair<char,string>('9',"1001"));
    HexToBinHelper.insert(pair<char,string>('a',"1010"));
    HexToBinHelper.insert(pair<char,string>('b',"1011"));
    HexToBinHelper.insert(pair<char,string>('c',"1100"));
    HexToBinHelper.insert(pair<char,string>('d',"1101"));
    HexToBinHelper.insert(pair<char,string>('e',"1110"));
    HexToBinHelper.insert(pair<char,string>('f',"1111"));
    string s="";
    for(auto h:Hex){
        s+=HexToBinHelper[h];
    }
    Bitset b(s);
    return b;
}

int Bitset::BinToDec(Bitset bin){
    int dec=0;
    int twoPow=1;
    for(int i=bin.size()-1;i>=0;i--){
        if(bin.stringform()[i]=='1')dec+=twoPow;
        twoPow*=2;
    }
    return dec;
}