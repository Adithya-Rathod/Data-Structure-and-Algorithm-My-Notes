#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &x, int a, int b){
    int c = x[a];
    x[a] = x[b];
    x[b] = c;
}


void insert (vector <int> &arr, int n, int value){

    arr.push_back(value);
    int i = n+1;
    while(i>=1)
    {   
        if(arr[i-1]>arr[i/2-1])
          { swap(arr, i-1, i/2 -1);
            i = i/2;
          }
        else {
            return;
        }
    }
}

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
    vector <int> arr ={50 ,30, 20, 18, 15};
    int n = arr.size();
    int value = 40;
    for(int i : arr)
        cout<<i<<" ";
        cout<<endl;
//    insert(arr, n, value);
    
//     for(int i : arr)
//         cout<<i<<" ";
//         cout<<endl;
    del(arr, n);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}