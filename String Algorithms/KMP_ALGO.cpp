#include <bits/stdc++.h>
using namespace std;

//pi-table or prefix table or fail function or prefix function or  
vector<int> pi(string Pattern)
{
    int m = Pattern.size();
    vector<int> F(m, 0);
    int i = 1, j = 0;
    // prefix table in O(m);
    while (i < m)
    {
        if (Pattern[i] == Pattern[j])
        {
            F[i] = ++j;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
    return F;
}

int KMP(string Text, string Pattern)
{
    int i{0}, j{0};
    int n = Text.size();
    int m = Pattern.size();
    vector<int> F = pi(Pattern); //creating the pi table
    
    while (i < n)
    {
        if(Text[i] == Pattern[j])
        {
            if(j==m-1)
                return i-j;
            else
            {
                i++;
                j++;
            }
        }
        else if(j>0)
            j = F[j-1];
        else
            i++;
    }
    return -1;
}
int main()
{
    string t, p;
    cin>>t>>p;
    cout<<KMP(t,p);
    return 0;
}