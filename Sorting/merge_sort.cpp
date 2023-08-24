#include<bits/stdc++.h>
using namespace std;
//merging the two subarrays
void merge(vector<int> &a, int lo, int mid, int hi)
{
    vector<int> temp;
    int left = lo;
    int right = mid +1;
    while(left<=right && right<=hi)
    {
        if(a[left]<=a[right])
            temp.push_back(a[left++]);
        else
            temp.push_back(a[right++]);
    }
    while(left<=mid)
        temp.push_back(a[left++]);
    
    while(right<=hi)
        temp.push_back(a[right++]);

    for(int i= lo; i<=hi ; i++)
    {
        a[i] = temp[i-lo];
    }
}
//dividing into two subarrays 
 void mergeSort(vector<int> &a, int lo, int hi)
 {
    if(lo>=hi)
        return;
    int mid = (lo +hi)/2;

    mergeSort(a, lo, mid);

    mergeSort(a,mid+1, hi);
    
    merge(a, lo, mid, hi);
}

void display(vector<int> &a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
  vector<int> a={5,2,6,8,1,3,7,4,9,8};
    int n= a.size();

    display(a, n);
    cout<<endl;
    mergeSort(a, 0, n-1);
    display(a, n);

return 0;
}