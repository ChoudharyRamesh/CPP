#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void reverse_str(string& str) ;
string add( string X,string Y);
void reverse_str(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

string add( string X,string Y) 
 {   string A = X; reverse_str(A);
    string B = Y;  reverse_str(B);
    int alen = A.length(); 
    int blen = B.size(); 
    if(alen>blen){ B.resize(A.size(),'0');}
    if(alen<blen){ A.resize(B.size(),'0');}
     reverse_str(A);   reverse_str(B);
    string temp;  temp.resize(A.size()); 
    int carry =0,count =1;
    string final,final_temp;
    char  m_result ,m_carry;
    for(int i=alen-1 ;i>=0;i--)
     {    int temp_up =(int)A[i]-48;
          int temp_down =(int)B[i]-48;
          string stemp =to_string((temp_up+temp_down)+carry);
          if(stemp.size()==2) {
           m_result = stemp[1];
            m_carry = stemp[0];
          }else{   m_result = stemp[0];
                   m_carry = '0';
             }
            carry =(int)m_carry -48;
            final_temp.resize(count,m_result); count++;
            if(i==0)
            {  if(m_carry!='0'){ final_temp.resize(count,m_carry); }
               reverse_str(final_temp);
               final=final_temp;  }
      }
      return final;
  }
  
int main() {
   cout<<add("1250","50");  
}
  
