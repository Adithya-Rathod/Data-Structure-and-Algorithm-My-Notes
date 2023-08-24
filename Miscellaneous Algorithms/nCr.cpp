#include<bits/stdc++.h>
using namespace std;

int C(int n ,int r)
{
    int res=1;
    for(int i = 0; i<r; i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
} 
int main()
{
 
return 0;
}