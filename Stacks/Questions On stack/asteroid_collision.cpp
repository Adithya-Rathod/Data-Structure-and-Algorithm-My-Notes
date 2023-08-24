#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& gin) {
        vector<int> res;
        for(auto &it : gin)
        {
            bool flag = true;
            while(!res.empty() && it<0 && res.back()>0)
            {
                if(res.back() + it<0)
                    res.pop_back();
                else if(res.back() + it > 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    flag = false;
                    res.pop_back();
                    break;
                }
            }
            if(flag) res.push_back(it);
            }
        return res;
    }
};
int main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
       
        Solution jk;
        vector<int> res = jk.asteroidCollision({-5,10,5});
        for(auto it : res)
            cout<<it<<" ";
        cout << endl;
    }
    return 0;
}