#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n];
    int i =0;
    for(i; i<n; i++)
    {
        cin>>A[i];
    }
    i = 0;
    sort(A, A+n);
    
    cout<<max(A[0]*A[1]*A[n-1], A[n-3]*A[n-2]*A[n-1]);
    return 0;
}