#include <bits/stdc++.h>
using namespace std;


class prime
{
public:
    vector<int> primeFactorize(int n)
    {
        vector<int> res;
        // all the 2 's that can come out of n
        while (n & 1 == 0)
        {
            res.push_back(2);
            n >> 2;
        }
        // check for all the odd nos jab tak divide ho
        for (int i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                res.push_back(i);
                n /= i;
            }
        }

        // case when the n is a prime no.
        if (n > 2)
            res.push_back(n);

        return res;
    }

    bool checkIfPrime(int n)
    {
        return countDivisors(n) == 2;
    }

    int countDivisors(int n)
    {
        /*
            i<sqrt(n) bhi kar sakte the but sqrt(n) will have a logn complexity
            so uss case mei overal tc would have been O(sqrt(n)*log(n))

            if n = 24

            1 x 24
            2 x 12
            3 x 8
            4 x 6
         ------------   iske baad repeat ho rha hai
            6 x 4
            8 x 3
            12 x 2
            24 x 1


        */
        int cnt = 0;
        // overall TC - O(sqrt(n))
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;

                if (n / i != i) // because n = 36 mei 6 x 6 do bar count hona nhi chahiye
                    cnt++;
            }
        }
        return cnt;
    }

    vector<int> printDivisors(int n)
    {
        vector<int> res;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                res.push_back(i);
                if(n/i != i)
                {
                    res.push_back(n/i);
                }
            }
        }
        return res;
    }
    //sieve computation ki TC = O(n*log(log(n)))
    vector<bool> buildSieve(int n)
    {
        vector<bool> sieve(n+1,true);

        sieve[0] = sieve[1] = false;

        for(int i = 2; i<=n; i++)   //optimization i< sqrt(N) I.E. i*i<=n
        {
            if(sieve[i]==true)
            {
                for(int j = 2*i; j<=n; j+=i) //optimization j = i*i (uske pehle ka ho gaya na)
                    sieve[j] = false;
            }
        }
        return sieve;
    }

};
    
int main()
{

    return 0;
}

/*
if we are declaring inside the main function or any other function then the 
maximum sizes of arrays are
    int a[1e6];
or  bool a[1e7];

if we need more than that then declare array globally globally ka limit
    int a[1e7];
or  bool a[1e8];
*/