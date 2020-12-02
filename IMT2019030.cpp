#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

#include "IMT2019030_DirectMappedCache.h"
#include "IMT2019030_SetAssociativeCache.h"
#include "Colors.h"

//Given conditions
#define SIZE 256*1024
#define BLOCKSIZE 4
#define WAYS 4

Colors c;

//function to print the results onto the command prompt
void PrintOutput(string file,int Hits,int Miss,double HitRate,double MissRate,string cachetype){
    cout<<endl;
    if(cachetype=="DM")
    cout<<c.ANSI_YELLOW<<"____DM Cache____"<<c.ANSI_RESET<<endl;
    if(cachetype=="SA")
    cout<<c.ANSI_YELLOW<<"____SA Cache____"<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Current File : "<<c.ANSI_RESET<<c.ANSI_WHITE<<file<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Number of Hits : "<<c.ANSI_RESET<<c.ANSI_WHITE<<Hits<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Number of Miss : "<<c.ANSI_RESET<<c.ANSI_WHITE<<Miss<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Hit Rate : "<<c.ANSI_RESET<<c.ANSI_WHITE<<HitRate<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Miss Rate : "<<c.ANSI_RESET<<c.ANSI_WHITE<<MissRate<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_RED<<"Hit To Miss Ratio : "<<c.ANSI_RESET<<c.ANSI_WHITE<<(double)(HitRate)/(MissRate)<<c.ANSI_RESET<<endl;
    cout<<c.ANSI_GREEN<<"____Finished Execution____"<<c.ANSI_RESET<<endl<<endl;
}

int main(){
    vector<string>files={"traces/gcc.trace","traces/gzip.trace","traces/mcf.trace","traces/swim.trace","traces/twolf.trace"};

    for(int i=0;i<5;i++){

        //We can even place them outside the loop and clear the cache for every trace file
        DMCache DMcache(SIZE,BLOCKSIZE);
        SACache SAcache(SIZE,WAYS,BLOCKSIZE);

        fstream file;
        file.open(files[i]);

        //Taking input from the files inside the traces folder
        int DMHits=0,DMMiss=0;
        int SAHits=0,SAMiss=0;
        string field1,field2,field3;
        while(file>>field1>>field2>>field3){
            string Address=field2;
            
            //calculating the #hits and #miss for both DM and CA cache for current address
            if(DMcache.CheckAndHit(Address)){
                DMHits++;
            }
            else{
                DMMiss++;
            }
            
            if(SAcache.CheckAndHit(Address)){
                SAHits++;
            }
            else{
                SAMiss++;
            }
        }

        //calculate the hit and miss rates
        double DMHitRate=(double)(DMHits*1.0)/(DMHits+DMMiss);
        double DMMissRate=(double)(DMMiss*1.0)/(DMHits+DMMiss);

        double SAHitRate=(double)(SAHits*1.0)/(SAHits+SAMiss);
        double SAMissRate=(double)(SAMiss*1.0)/(SAHits+SAMiss);

        //print the output
        PrintOutput(files[i],DMHits,DMMiss,DMHitRate,DMMissRate,"DM");
        PrintOutput(files[i],SAHits,SAMiss,SAHitRate,SAMissRate,"SA");

        //close the file
        file.close();
    }

    return 0;
}