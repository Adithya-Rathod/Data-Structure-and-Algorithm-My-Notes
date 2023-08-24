#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> &a , pair<int,int> &b)
{
     return( a.first<b.first )|| (a.first == b.first && a.second>b.second); 
} 
void display(vector<pair<int,int>> &v)
{
    for(auto it: v)
        cout<<it.first << " " << it.second<<endl;
}
int main()
{   
    vector<pair<int, int>> v = {
                                {1,2}, {4,1} ,{ 5,3}, {2,7} ,{4,7}};

    sort(v.begin(), v.end());
    // lamba body declaration of the custom comparator 
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
        return( a.first<b.first )|| (a.first == b.first && a.second>b.second);});

    sort(v.begin(), v.end(), cmp);
    swap(v[0], v[1]);
return 0;
}