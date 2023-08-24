#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &arr, int lo, int hi, int target)
{
    if(lo>=hi) return lo;
    int mid= (lo+hi)/2;
    if(target > arr[mid])
        return bs(arr, mid+1,hi, target);
    else if(arr[mid>target])
        return bs(arr, lo, mid, target);
    else
        return mid;
} 
int main()
{
    vector<int> a = {1,2,3,5,6,7,8,9,10};
    int ans = bs(a, 0, 8, 4);
    cout<< a[ans];
return 0;
}