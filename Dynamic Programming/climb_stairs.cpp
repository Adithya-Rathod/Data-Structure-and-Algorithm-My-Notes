/*Either 1 step at a time or 2 step at a time*/

#include<bits/stdc++.h>
using namespace std;
//recursive solution 
//but since we have overlapping solutions so we need not recalculate those 
//TC :- O(N)
//SC:- O(N) -> recurssion stack space
int fun(int n)
{
    if(n<=1) return 1;

     return fun(n-1) + fun(n-2);
} 


 //memoization
 //TC:- O(N);
 //SC:= O(N)->recurrsion stack space + O(N)->extra array
 int funm(int n,vector<int> &dp)
 {
    if(n<=1) return 1;

    if(dp[n] !=  -1) return dp[n];

    return dp[n] = funm(n-1, dp) + funm(n-2, dp);
 }
 //tabulation
 //TC:- O(n);
 //SC:- O(n);->array
int funt(int n, vector<int> &dp)
{
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i<=n ;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
//space optimization
 //TC:- O(n);
 //SC:- O(1);
int funs(int n)
{
    if(n<=1) return 1;
    int a =1;   
    int b=1;    
    int sum =0;
    for(int i =2; i<n; i++)
    {
        sum = a+b;
        a= b;
        b = sum;
    }
    return sum;
}
//we were able to do this bc our result of currrent only
//depended on the values of previous so no need to save the history of other 

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    fun(n);
return 0;
}