#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr)
{
    //assumed that there exist a solution such only one number exist which is more \
  than the 
    int maj = arr[0];
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        //what it signifies if count is 0 ?\
        => it signinfies that till the current i (say m elments), \
        there are m/2 of the current majority elements and other m/2 \
        are not equal to the assusmed majority element meaning in the m \
        elements ka subarray we don't have any element which is >m/2 which\
         is actually desired so now u can assum a new majority element bc\
         purana wala toh nhi tha major...
        if (count == 0)
            maj = arr[i];

        if (maj == arr[i])
            count += 1;
        else
            count -= 1;
    }
    return maj;
}
int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
    return 0;
}