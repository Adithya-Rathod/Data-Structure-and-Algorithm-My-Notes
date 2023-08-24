#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    int  n =arr.size();
    int brkIndex=-1;
    //finding the break point
    for(int i = n-2; i>=0; i--)
    {
        if(arr[i]<arr[i+1])
        {
            brkIndex = i;
            break;
        }
    }
    //condition when the array is sorted in the descending  order so the next permutation will just be the ascending order bc no more idhar udhar wala permuations are not possible
    if(brkIndex==-1)
    {
        reverse(arr.begin(),arr.end());
        return;
    }

    //swap with the first element from the last which is just greater than breakpoint .
    for(int i= n-1 ; i>brkIndex; i--)
    {
        if(arr[i]>arr[brkIndex])
            {
                swap(arr[i], arr[brkIndex]);
                break;
            }
    }
    //ab uss break ke baad jitne bhi hai un sab ka reverser order hi toh hai apna answer
    reverse(arr.begin() + (brkIndex+1) , arr.end());
} 

void display(vector<int> &v)
{
    for(auto it: v)
        cout<<it<<" ";
    cout<<endl;
}
int main()
{
    vector<int> a = {1,3,2,5,4};
    nextPermutation(a);
    display(a);
return 0;
}