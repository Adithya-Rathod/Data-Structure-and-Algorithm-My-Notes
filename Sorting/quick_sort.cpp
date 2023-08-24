/*using divide and conquer method 

i.e. method of partitioning
the best case tc is when the pivot comes exactly at the middle and divides the array into two subarrays of 
n/2 & n/2(left sub array and right sub array) this further divides into n/4 & n/4 & n/4  & n/4 
the top of the binary tree has n calls the next will have in total n calls such 
n, n/2, n/2^2, n/2^3 ... 1

so at n/2^k = 1 
k is height of the binary tree 
k = log_2(n) 
and at every level there are n calls 
so overal TC is n x log_2(n) */

#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    while(i<=j){
        while(i<=j && a[i]<=pivot) i++;
        while(i<=j && a[j]>=pivot) j--;
        if(i<j) 
            swap(a[i], a[j]);
    }
    
    swap(a[low], a[j]);
    return j;
} 

void quicksort(int a[], int low, int high){
    if(low<=high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p-1);
        quicksort(a, p+1, high);
    }
}

void display(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    int a[]= {3,3,2,6,4,3,7,9,8};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<"before sorting : \n";
    display(a, n);

    quicksort(a, 0, n-1);
    
    cout<<"after sorting : \n";
    display(a, n);

    return 0;
}