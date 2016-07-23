#include "StopWatch.h"
#include <ctime>
#include <iostream>
using namespace std;



// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
double stopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}

void stopWatch::start()
{
   _time1 = getProcessTime();
   cout<<"started"<<endl;
    }

void stopWatch::stop()
{
    _time2 = getProcessTime();
    cout<<"Stopped"<<endl;
    cout<<endl;
    getTime();
    }
    
 void stopWatch::getTime()
 {
     int ms=0;
     int seconds=0;
     int minutes=0;
     
     
     _timeTaken = _time2 - _time1;
     
     if(_timeTaken>60)
     {
        minutes = _timeTaken/60;
        seconds = _timeTaken-minutes*60;   
        ms =  (_timeTaken-(minutes*60+seconds))*1000;         
     }    
       else{
        seconds = _timeTaken;
        ms = _timeTaken*1000-seconds*1000; 
       }
        
       
     cout<<"Time taken: "<<minutes<<":"<<seconds<<":"<<ms<<endl;
     cout<<_timeTaken<<endl;
     //return _timeTaken; 
     }   
     
 void longProgram()
 {
     for(int i = 0; i<1000000; i++)
     {
         cout<<i<<endl;
         }
     
     }    

int main()
{
    stopWatch watch{};
    
    watch.start();
    longProgram();
    watch.stop();
}