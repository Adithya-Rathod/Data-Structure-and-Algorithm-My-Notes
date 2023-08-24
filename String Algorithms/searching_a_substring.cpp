/*Brute force*/
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string T, P;
    cin>>T>>P;
    bool flag=false;
    int n = T.size();
    int m = P.size();
    int i;
    for( i = 0; i<=n-m; i++)
    {
        int j=0;
        while(j<m)
        {
            if(T[i+j] == P[j])
                {
                    j++;
                }
            else
                break;
        }
        if(j==m){
            flag=true; 
            break;
            }
    }
    if(flag) cout<<i+1<<endl;
    else cout<<"MAA CHUDA"<<endl;
return 0;
}