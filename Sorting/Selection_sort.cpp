#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    int i, j, min_idx;
    for(i=0; i<n;i++)
    {
        min_idx = i;
        for(j=i+1; j<n; j++)
        {
            if(a[min_idx]>a[j])
                min_idx = j;
        }

        if(min_idx != i)
        {
            swap(a[min_idx], a[i]);
        }
    }
}
void print_array(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<',';
    }
}

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;

}
void display(int arr[], int n){
    for(int i= 0; i<n; i++)
        cout<<arr[i]<<" ";
    
}

int main()
{
    int a[]={5,2,6,8,1,3,7,4,9,8};
    int n= sizeof(a)/sizeof(a[0]);

    display(a, n);
    cout<<endl;
    selectionSort(a, n);
    display(a, n);

    

}