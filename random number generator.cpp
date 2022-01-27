#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const string random(  int max )
{
    if(max<=0){ max =1; }
   string final;
 //  int length = 1;
   int temp  = 0;
   srand(time(nullptr)-rand());
     for( int i =0;i<max;i++)
     {  temp =  rand()%10;
        if( i==0 && temp ==0)
           {  i--;  continue;  }
         final.push_back((char )(temp+48));
     }
 return final;
}

int main()
{ 
   cout<<random(15)<<endl;
}
