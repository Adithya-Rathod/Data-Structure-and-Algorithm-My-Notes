#include<iostream>
using namespace std;
 class maxheap{
    int *arr;
    int count;
    int capacity;
    public:
        maxheap(int capacity)
        {
            this->capacity = capacity;
            this->arr = new int[capacity];
            this->count = 0;
            if(this->arr == NULL)
            {
                cout<<"memory error"<<endl;
                return;
            }
        }
        int parent(int i)
        {
            if(i<=0 || i>= this->count)
                return -1;
            return (i-1)/2;
        }
        int leftchild(int i)
        {   
            int left = 2*i+1;
            if(left>=this->count)
                 return -1;
                 return left;
        }
        int rightchild(int i)
        {   
            int right = 2*i+2;
            if(right>=this->count)
                return -1;
                 return right;
        }
        int maxi()
        {
            if(this->count == 0)
                return -1;
            return arr[0];
        }
        void heapify(int i)
        {
            int l, r, largest;
            l = leftchild(i);
            r = rightchild(i);
            if(l<=this->count && this->arr[l]>this->arr[i])
                largest = l;
            else 
                largest = i;
            if( r<=this->count && this->arr[largest]<this->arr[r])
                largest = r;
            if(largest!=i)
                {
                    int temp = this->arr[largest];
                     this->arr[largest] = this->arr[i];
                     this->arr[i]= temp;

                     heapify(largest);
                }
        }
        void heapifyarr(int a[], int n)
        {
           for(int i=0; i<n;i++)
            this->arr[i]=a[i];
            this->count =n;
            for(int i=(n-1)/2; i>=0; i++ )
            {
                heapify(i);
            }
        }
        void print()
        {
            for(int i=0; i<count;i++)
                cout<<this->arr[i];
        }
 };

int main()
{
    maxheap h1(5);
    int array[]={2,1,3,4,6};
    h1.heapifyarr(array, 5);
    h1.print();
return 0;
}