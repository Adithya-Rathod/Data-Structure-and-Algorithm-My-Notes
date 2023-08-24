#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, lower, high) for(ll i = lower; i< high; i++)
#define rloop(i, high, low) for(ll i = high-1; i>=low; i--)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((ll)(x).size())
#define M 1000000007
 
void solve()
{
    string s;
    cin>>s;
    stack<char> st;
    for(auto it : s)
    {
        if(it=='(' || it=='{' || it =='[')
        {
            st.push(it);
        }
        else if(it ==')')
        {
            if(st.top()=='(')
                {
                    st.pop();
                }
            else{
                cout<<"INVALID";
                return;
            }
        }
        else if(it =='}')
        {
            if(st.top()=='{')
                {
                    st.pop();
                }
            else{
                cout<<"INVALID";
                return;
            }
        }
        else if(it ==']')
        {
            if(st.top()=='[')
                {
                    st.pop();
                }
            else{
                cout<<"INVALID";
                return;
            }
        }
    }
    if(st.empty())
        cout<<"VALID";
    else
        cout<<"INVALID";
}
 
int main()
{
ll t=1;
cin>>t;
while(t--){
solve();
cout<<endl;
}
    return 0;
}