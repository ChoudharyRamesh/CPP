#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void reverse_str(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]);
} 

string add( string X,string Y) 
{   string A = X;  reverse_str(A);
    string B = Y;  reverse_str(B);
    int alen = A.length(); 
    int blen = B.size(); 
    if(alen>blen){ B.resize(A.size(),'0');}
    if(alen<blen){ A.resize(B.size(),'0');}
     alen = A.length(); 
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
  
string multiply( string X,string Y) 
{   string A,a=X;
    string B,b=Y;
    if(a.size()>=b.size())
        { A =a; B=b; }
        else{ A=b; B=a; } 
    int alen = A.length(); 
    int blen = B.size();  
    string final[blen];
    
// loop for multiply    
  for( int down=blen-1; down>=0; down--)
   { string final_temp;
      int carry =0;
      int count =1;
      final_temp.clear(); 
     char down_temp = B[down];
     int down_tmp =(int)down_temp-48;
     
    for(int up=alen-1; up>=0; up--)
      {  char m_result;
          char m_carry;
         char up_temp =A[up]; 
         int up_tmp =(int)up_temp-48;
           string stemp =to_string((down_tmp*up_tmp)+carry);
          if(stemp.size()==2) {
           m_result = stemp[1];
            m_carry = stemp[0];
          }else{   m_result = stemp[0];
                   m_carry = '0';
             }
            carry =(int)m_carry -48;
            final_temp.resize(count,m_result); count++;
            if(up==0)
            {  if(m_carry!='0'){ final_temp.resize(count,m_carry); count++; }
               reverse_str(final_temp);
               final[blen-down-1]=final_temp;
               final[blen-down-1].resize(((final[blen-down-1].size())+blen-down-1) ,'0');
               cout<<final[blen-down-1]<<endl; }
      }
    }
string temppp =final[0];
    for( int i=0;i<blen-1;i++)
     {  temppp = add(temppp,final[i+1]);
     }
     cout<<temppp<<endl;
    return temppp;     
}
     
int main()
{ multiply("654154154151454545415415454","63516561563156316545145146514654");
  
}    
