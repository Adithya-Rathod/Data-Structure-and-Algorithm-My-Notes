#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:

    vector<int> root;
    int leftChild(int i)
    {
        return 2 * i;
    }
    int rightChild(int i)
    {
        return 2 * i + 1;
    }
    int parent(int i)
    {
        return i / 2;
    }
    void max_heapify(int i, int n)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest;
        if (l <= n && root[l - 1] > root[i - 1])
            largest = l;
        else
            largest = i;
        if (r <= n && root[r - 1] > root[largest - 1])
            largest = r;

        if (largest != i)
        {
            swap(root[i - 1], root[largest - 1]);
            max_heapify(largest, n);
        }
        return;
    }
    void percolateDown(int i, int n)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest;
        if (l <= n && root[l - 1] > root[i - 1])
            largest = l;
        else
            largest = i;
        if (r <= n && root[r - 1] > root[largest - 1])
            largest = r;

        if (largest != i)
        {
            swap(root[i - 1], root[largest - 1]);
            percolateDown(largest, n);
        }
        return;
    }
    void percolateUp(int i, int n)
    {
        int p = parent(i);
        int l = i;
        int r = i + 1;
        int largest;
        if (l > 1 && l <= n && root[p - 1] < root[l - 1])
            largest = l;
        else
            largest = p;

        if (r > 2 && r <= n && root[largest - 1] < root[r - 1])
            largest = r;
        if (largest != p)
        {
            swap(root[p - 1], root[largest - 1]);
            percolateUp(largest, n);
        }
    }
    void build_Heap()
    {
        int n = root.size();
        int k = floor(n / 2);
        for (int i = k; i > 0; i--)
        {
            max_heapify(i, n);
        }
    }
    Heap(vector<int> &a)
    {
        root = a;
        build_Heap();
    }
    void insert(int x)
    {
        root.push_back(x);
        build_Heap();
    }
    int heap_maximum()
    {
        if (root.empty())
            throw std::out_of_range("Heap is Empty");
        else
            return root[0];
    }
    int heap_extract_max()
    {
        if (root.empty())
            throw std::out_of_range("Heap is Empty");
        else
        {
            int max = root[0];
            swap(root[0], root.back());
            root.pop_back();
            max_heapify(1, root.size());
            return max;
        }
    }
    vector<int> heapsort()
    {
        vector<int> copy = root;
        vector<int> result;
        int len = root.size();
        for (int i = len; i >= 2; i--)
        {
            swap(root[i - 1], root[1 - 1]);
            result.push_back(root.back());
            root.pop_back();
            max_heapify(1, root.size());
        }
        result.push_back(root.back()); // last remaining node
        root = copy;                   // retain the root back to original
        return result;
    }
    void update(int position, int newval)
    {
        if (root.empty())
            throw std::out_of_range("Heap is Empty");
        else
        {
            root[position - 1] = newval;
            build_Heap();
        }
    }
    void destroy()
    {
        if (root.empty())
            return;
        else
            root.clear();
    }
    void pop(int position)
    {
        if (root.empty())
            throw std::out_of_range("Heap is Empty");
        else
        {
            swap(root[position - 1], root[root.size() - 1]);
            root.pop_back();
            percolateDown(position, root.size());
        }
    }
    void popfound(int x) // finding an element then deleting it
    {
        for (auto it = 0; it < root.size(); it++)
        {
            if (root[it] == x)
            {
                pop(it + 1);
            }
        }
    }
};

// algo to find all the elements less than k
void lessthan(Heap heap, int position, int k)
{
    if (!heap.root.empty() && position>=1 && position<=heap.root.size() && heap.root[position -1]<k)
    {
        cout<<heap.root[position-1];
        lessthan(heap, 2*position, k);
        lessthan(heap, 2*position + 1, k);
    }
    else
        return;
}
void print(vector<int> ans)
{
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout<<endl;
}
int main()
{
    vector<int> a = {4, 2, 1, 6, 8, 7};
    Heap h1(a);
    lessthan(h1, 1, 5);
    // vector<int> ans = h1.heapsort();
    return 0;
}
