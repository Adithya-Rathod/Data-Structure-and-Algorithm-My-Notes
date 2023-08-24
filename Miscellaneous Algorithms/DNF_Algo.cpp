#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//DNF Algorithm -> dutch national flag problem
//red -> 0
//white ->1
//blue ->2
//joh joh 0 hai usko array ke start mei rakhe pointer pe lao and increment that pointer
//joh joh 2 hai usko array ke end mei rakhe pointer pe lao and decrement that pointer
//joh joh 1 hai usko vaise right rehne do and aage bado
    void sortColors(vector<int>& nums) {
        //left ke pehle and right ke baad waale elements required hai aisa rakhna hai
        int left=0, right = nums.size()-1;
        int n = nums.size();
        int i=0;
        while(i<=right)
        {
            if(nums[i]==0)
            {
                swap(nums[left++], nums[i++]);
            }
            else if(nums[i]==2)
            {
                swap(nums[right--],nums[i]);
            }
            else
                i++;
        }
    }
};
int main()
{
int t;
cin>>t;
while(t--){
 Solution jk;
 
cout<<endl;
}
    return 0;
}