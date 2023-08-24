#include<bits/stdc++.h>
using namespace std;
void del (vector <int> &a, int n)
{
    a[0]=a[n-1];
    a.pop_back();
    n = n-1;
    int i=1;
    while(i>=n && 2*i<=n){

        int left =  2*i;
        int  right = 2*i +1;
        int larger = a[left-1] > a[right-1] ? 2*i : 2*1 +1;
            if(a[larger-1]>a[i-1])
                {
                    swap(a, larger-1, i-1);
                    i=larger;
                }
            else{
                return;
            }    
    }
}
int main()
{   
    return 0;
}