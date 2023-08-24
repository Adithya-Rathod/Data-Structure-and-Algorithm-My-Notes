#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;

}

void display(int arr[], int n){
    for(int i= 0; i<n; i++)
        cout<<arr[i]<<" ";
    
}

int main()
{
    int arr[]={4,1,2,5,8,7,9,3,6,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    display(arr, n);
    cout<<endl;
    for(int i= 0; i<n; i++)
    
        for(int j=0; j<n;  j++)
        
            if(arr[j]>arr[j+1])
             
                swap(&arr[j], &arr[j+1]);
        
    display(arr, n);    
    return 0;
}