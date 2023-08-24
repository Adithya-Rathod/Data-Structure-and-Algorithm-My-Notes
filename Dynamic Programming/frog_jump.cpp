
/* forg only has 1 jump or 2 jumps step at a time at every level there is energy find the minimum energy required to reach the Nth level*/
#include <bits/stdc++.h>
using namespace std;

//recurrence relation
//but if we draw the recurrsion tree of the given recurrence relation we can see we havve overlapping solutions
int jump(int n, vector<int> &H)
{
    if(n == 0) return 0;

    int left = jump(n-1, H) + abs(H[n] - H[n-1]);
    int right =INT_MAX;
    if(n>1)
         right = jump(n -2, H) + abs(H[n] - H[n-2]);
    
    return min(left, right);

}
//memoization
int jumpm(int n, vector<int> &H, vector<int> &dp)
{
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    
    int left = jumpm(n-1, H, dp) + abs(H[n] - H[n-1]);
    int right =INT_MAX;
    if(n>1)   
         right = jumpm(n -2, H, dp) + abs(H[n] - H[n-2]);

    return dp[n] = min(left, right);

}
//tabulation
int jumpt(int n, vector<int> &H)
{
    vector<int> dp(n, -1);
    dp[0]=0;
    for(int i = 1; i<n; i++)
    {
        int left  = dp[i-1] + abs(H[i] -H[i-1]);
        int right =INT_MAX;
        if(i>1)
            right= dp[i-2] + abs(H[i-2] - H[i]);

        dp[i] = min(left, right);
    }
    return dp[n-1];
}

//space optimization
int jums(int n, vector<int> &h)
{
    int prev1 = 0, prev2{0};
    for(int i= 1; i<n ; i++)
    {
        int firsStep = prev1 + abs(h[i] - h[i-1]);
        int secondstep =INT_MAX;
        if(i>1)
            secondstep = prev2 + abs(h[i] - h[i-2]);
        
        int curri = min(firsStep, secondstep);
        prev2 = prev1;
        prev1 = curri;

    }
    //because after i reaches n prev will be for n-1 that is the answer
    return prev1;

}
int main()
{
    int n;
    cin >> n;
    vector<int> heigthEnergy(n);
    for (int i = 0; i < n; i++)
        cin >> heigthEnergy[i];
    vector<int> dp(n);
    return 0;
}