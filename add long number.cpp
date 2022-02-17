#include<iostream>
#include<string>
#include<stdio.h>


void reverse_str(std::string & str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
}

std::string bigInt_add( std::string X,std::string Y)
{
    std::string A = X; reverse_str(A);
    std::string B = Y;  reverse_str(B);
    int alen = A.length();
    int blen = B.size();

    if(alen>blen) B.resize(A.size(),'0');
    if(alen<blen) A.resize(B.size(),'0');

    reverse_str(A);
    reverse_str(B);

    std::string temp;
    temp.resize(A.size());
    int carry =0,count =1;
    std::string final,final_temp;
    char m_result ,m_carry;

    for(int i=alen-1 ;i>=0;i--)
    {
        int temp_up =(int)A[i]-48;
        int temp_down =(int)B[i]-48;
        std::string stemp = std::to_string((temp_up+temp_down)+carry);

        if(stemp.size()==2) {
            m_result = stemp[1];
            m_carry = stemp[0];
        }
        else
        {
            m_result = stemp[0];
            m_carry = '0';
        }

        carry =(int)m_carry -48;
        final_temp.resize(count,m_result); count++;

        if(i==0)
        {
            if(m_carry!='0'){ final_temp.resize(count,m_carry); }
            reverse_str(final_temp);
            final=final_temp;
        }
    }

    return final;
}

int main()
{
    std::cout<<bigInt_add("18797981465654652465","11")<<std::endl;
}

