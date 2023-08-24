#include<bits/stdc++.h>
using namespace std;

void heapSortez(vector<int> &arr)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int i=0;
    while(!pq.empty())
    {
            arr[i++] = pq.top();
            pq.pop();
    }
}

void print(vector<int> arr)
{
    for(auto &it : arr)
        cout<<it<<" ";
        cout<<"\n";    
}

int main()
{
    vector<int> arr = {5,1,2,4,7,8,3,11,6,9,10};
    int n = arr.size();
    
    return 0;
}                                                               