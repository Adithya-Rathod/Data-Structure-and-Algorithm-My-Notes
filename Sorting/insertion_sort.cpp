#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i= 0; i<n; i++)
        cout<<arr[i]<<" ";
    
}

int main()
{
    int a[]={2,4,3,5,1};
    int n = sizeof(a)/sizeof(a[0]);

    display(a, n);
    cout<<endl;

    int key, j;
    for(int i=1 ; i<n; i++)
    {
        key = a[i];
        j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--; 
        }
        a[j+1] = key;
    }

    display(a, n);
}