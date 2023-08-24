#include <bits/stdc++.h>
using namespace std;

// using binary exponentiation

double pow(int x, int n)
{
    double res = 1.0;
    long temp = n;
    if(temp<0) temp = -temp;
    while (temp)
    {
        if (temp & 1)
        { // odd
            res = res * x;
            temp = temp - 1;
        }
        else
        {
            x = x * x;
            temp = temp>>2; //divide by 2
        }
    }
    if(n<0) return 1.0/res;
    return res;
}

int main()
{

    return 0;
}