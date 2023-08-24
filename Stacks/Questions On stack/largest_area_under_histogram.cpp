#include<bits/stdc++.h>
using namespace std;
 
 //brute force 
 //checking the left range and right range of every element to find the length of the histogram
 //TC :-> O(N^2)

int main()
{
 vector<int> a={6, 2, 5, 4, 5, 1, 6};
 int  n =a.size();
 int maxArea=0;
 for(int i=0; i<n;i++)
 {
    int left=i; 
    int right =i;
    while(left>=0 && a[i]<=a[left])
        left--;
    while(right<n && a[i]<=a[right])
        right++;
     maxArea = max(maxArea, (right- left -1)*a[i] );   
 }
 cout<<endl<<maxArea;
return 0;
}