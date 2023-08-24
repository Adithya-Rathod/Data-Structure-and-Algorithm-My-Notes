#include <bits/stdc++.h>
using namespace std;

const int base = 101;

//Rabin's Fingerprint Funtion
int hashfunction(string key)
{
    int len = key.size();
    int hashCode=key[0];
    for(int i= 1; i<len; i++)
    {
        //Horner's Rule
        hashCode=(hashCode)*base + key[i]; 
    }

    return hashCode;
}

int RabinKarp(string Text, string Pattern)
{
    int n = Text.size();
    int m = Pattern.size();
    //initial hashvalue for a window size of m
    //will take O(M) time to compute it initially but subsequently we won't requre the function bc we will rolling the hash function
    int windowHash = hashfunction(Text.substr(0, m));
   
    int patterHash = hashfunction(Pattern); 

    for(int i=0 ;i<=n-m; i++)
    {

        bool flag = false;
        if(patterHash == windowHash)
            {
                flag = true;
                int j=0;
                while(j<m && Text[i+j]==Pattern[j])
                    j++;
                if(j!=m)
                    flag = false;
            }
        if(flag)
            return i;

        //rolling hashfunction to maintain the window size and silde to the next window in O(1)
        if(i<n-m)
            windowHash= (windowHash - Text[i]*pow(base,m-1))*base + Text[i+m];

    }
    return -1;
}

int main()
{
    string Text, Pattern;
    cin>>Text>>Pattern;
    cout<< RabinKarp(Text,Pattern);
    return 0;
}