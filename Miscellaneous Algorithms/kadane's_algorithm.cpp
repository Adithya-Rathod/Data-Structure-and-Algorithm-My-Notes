#include<bits/stdc++.h>
using namespace std;
//linear time and constant space mei find the maximum sum of subarrray

 //kadane' algorithm \
main intutuion behind the algo is that we go on considering an array till we\
get a negative sum bc once we get a negative sum we will no longer need it
 int maxSubarray(vector<int> &a)
 {
    int sum = 0;
    int maxSum = INT_MIN;
    int n = a.size();
    for(int i=0 ;i<n; i++)
    {
        sum+=a[i];
        maxSum = max(maxSum, sum);

        if(sum<0) sum=0;
    }
 }
int main()
{
 
return 0;
}