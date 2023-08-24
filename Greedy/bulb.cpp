#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if(cost % 2==0)
            A[i] = A[i];
        else
            A[i] = !A[i];
        
        if(A[i] ==1)
            continue;
        else
            cost++;
    }
    cout<<cost;
    return 0;
}