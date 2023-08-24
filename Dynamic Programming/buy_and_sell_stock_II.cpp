#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int ind, int len, int buy, vector<vector<int>> &dp, vector<int> &arr)
    {
        if (ind == len)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        long profit = 0;
        if (buy)
            profit = max((-arr[ind] + f(ind + 1, len, 0, dp, arr)), (0 + f(ind + 1, len, 1, dp, arr)));
        else
            profit = max((arr[ind] + f(ind + 1, len, 1, dp, arr)), (0 + f(ind + 1, len, 0, dp, arr)));
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, n, 1, dp, prices);
    }
};
int main()
{

    return 0;
}