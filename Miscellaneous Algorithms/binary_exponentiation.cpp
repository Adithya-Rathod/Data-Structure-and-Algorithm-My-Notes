#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
// recurssive
long long pow(long long a, long long n)
{
    if (n == 0)
        return 1;
    long long res = pow(a, res);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}
//iterative     
long long powr(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a;
        a = a* a;
        n>>=1;
    }
    return res;
}
//if very large values of a and n;
long long power(long long a, long long n, long long m)
{
    a%=m;
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * (a%m);
        n>>=1;
    }
    return res;
}

int main()
{

    return 0;
}