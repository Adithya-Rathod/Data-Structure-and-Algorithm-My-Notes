#include <bits/stdc++.h>
using namespace std;

// recurreence relationon
// ulike the last question we have k jumps instead for 1 jump and 2 jump so we loop over all the jumps

//TC: O(N*K)
//SC: O(N)->recussionn stack space
int jump(int index, int k, vector<int> &H)
{
    if (index == 0)
        return 0;

    int minmumstep = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int jjump;
        if (index >= j)
            jjump = jump(index - j, k, H) + abs(H[index] - H[index - j]);
        else
            break;
        minmumstep = min(minmumstep, jjump);
    }
    return minmumstep;
}

// memoization
//TC: O(N*K)
//SC: O(N)->recussionn stack space + O(N)->array
int jumpm(int index, int k, vector<int> &H, vector<int> &dp)
{
    if (index == 0)
        return 0;

    int minmumstep = INT_MAX;
    if (dp[index] != -1)
        return dp[index];
    for (int j = 1; j <= k; j++)
    {
        int jjump;
        if (index >= j)
            jjump = jumpm(index - j, k, H, dp) + abs(H[index] - H[index - j]);
        else
            break;
        minmumstep = min(minmumstep, jjump);
    }
    return dp[index] = minmumstep;
}

// tabulation
//TC: O(N*K)
//SC: O(N)->array
int jumpt(int n, int k, vector<int> &h)
{

    vector<int> dp(n, -1);
    dp[0] = 0;
    int minimumStep = INT_MAX;
    for (int index = 1; index < n; index++)
    {
        for (int j = 1; j <= k; j++)
        {
            int jjump = 0;
            if (index >= j)
                jjump = dp[index - j] + abs(h[index - j] - h[index]);
            else
                break;
            minimumStep = min(minimumStep, jjump);
        }
        dp[index] = minimumStep;
    }
    return dp[n-1];
}

// cannot be space optimized as previous problem because earlier we had couple of steps so we just needed the history of the previous 2 but 
//here we will require the history of k last elements 
//so there will be a window of k elements which will move up by 1 element to the right so we can maintain a deque for that purpose 
//so we will have a space optimization of O(k) but in the worst case it will anyway go to O(n)
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