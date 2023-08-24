#include<bits/stdc++.h>
using namespace std;
 //By newton's method

    int mysqrt(double x)
    {
        if(x<=0)
            return -1;
        double guess = x;
        while(1)
        {
            double nextGuess = (guess + x/guess)/2.0;
            if(abs(nextGuess - guess) < 0.00001)
                return guess;
            
            guess = nextGuess;
        }

    }
int main()
{
    int n;
    cin>>n;
    cout<<mysqrt(n);
return 0;
}