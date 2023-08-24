#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int dividend, divisor;
    cin>>dividend>>divisor;
     int c;
        if(dividend>=0 && divisor>0)
            c=1;
        else if(dividend<0 && divisor>0)
           c=-1;
        else if(dividend>=0 && divisor<0)
            c=-1;
        else if(dividend<0 && divisor<0)
            c=1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int quo=0;
        while(dividend>divisor)
        {
            dividend = dividend - divisor;
            quo++;
        }
        cout<<quo*c;
return 0;
}