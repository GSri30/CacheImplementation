#ifndef COLORS_H_
#define COLORS_H_

#include<string>
using namespace std;

//Helper class used for output
//Contains various colors' codes
class Colors{
    public:
        string ANSI_RESET;
        string ANSI_BLACK;
        string ANSI_RED;
        string ANSI_GREEN;
        string ANSI_YELLOW;
        string ANSI_BLUE;
        string ANSI_PURPLE;
        string ANSI_CYAN;
        string ANSI_WHITE;
    public:
        Colors(){
            ANSI_RESET = "\u001B[0m";
            ANSI_BLACK = "\u001B[30m";
            ANSI_RED = "\u001B[31m";
            ANSI_GREEN = "\u001B[32m";
            ANSI_YELLOW = "\u001B[33m";
            ANSI_BLUE = "\u001B[34m";
            ANSI_PURPLE = "\u001B[35m";
            ANSI_CYAN = "\u001B[36m";
            ANSI_WHITE = "\u001B[37m";
        }
};

#endif