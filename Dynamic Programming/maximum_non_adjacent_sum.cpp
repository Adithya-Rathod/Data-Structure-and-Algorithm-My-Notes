#include <bits/stdc++.h>
using namespace std;

//reurssion but a exponential time complexity 
int maxisum(int index, vector<int> a)
{
    if(index == 0) return a[index];
    if(index <0) return 0; 

    int pick = a[index] + maxisum(index-2 , a);
    int notpick = 0 + maxisum(index-1 , a);

    return max (pick, notpick);
}

//memoization because we will have overlapping subproblems
//TC: reduced to O(N)
// SC: O(N) + O(N)
int maxisum_m(int index, vector<int> a , vector<int> &dp)
{
    if(index == 0) return a[index];
    if(index <0) return 0; 

    if(dp[index]!=-1)  return dp[index];
    int pick = a[index] + maxisum_m(index-2 , a, dp);
    int notpick = 0 + maxisum_m(index-1 , a, dp);

    return dp[index] = max (pick, notpick);

}
//tabulation 
//TC: reduced to O(N)
// SC: O(N)->array
int maxisum_T(int n, vector<int> a )
{
    vector<int> dp(n);
    dp[0] = a[0];
    for(int i=1; i<n; i++)
    {
        int pick = a[i];
            if(i>1)
                pick+=dp[i-2];
        int notpick = 0 + dp[i-1];

        dp[i] = min(pick,notpick);
    }
    return dp[n-1];
}
//space optimization
//because somewhere we just need the last two occurences 
//TC: O(N)
//SC: O(1)
int maxisum_space(int n, vector<int> a)
{
    int prev1 = a[0];
    int prev2 = 0; 
    for(int i=1; i<n ;i++)
    {
        int pick = a[i] ;
            if(i>1)
                pick+=prev2;
        int notpick = 0 + prev1;

        int curi = min(pick, notpick);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    return 0;
}