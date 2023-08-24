#include <bits/stdc++.h>
using namespace std;
class segmentTree
{
private:
    vector<int> tree;
    int n;

    void buildMAXTree(vector<int> &arr, int left, int right, int index)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        buildMAXTree(arr, left, mid, 2 * index + 1);
        buildMAXTree(arr, mid + 1, right, 2 * index + 2);
        tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
        return;
    }
    void buildSUMTree(vector<int> &arr, int left, int right, int index)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        buildSUMTree(arr, left, mid, 2 * index + 1);
        buildSUMTree(arr, mid + 1, right, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
        return;
    }
    int findMAX(int left, int right, int ql, int qr, int index)
    {
        if (left >= ql && right <= qr)
            return tree[index];

        if (ql > right || qr < left)
            return INT_MIN;

        int mid = (left + right) / 2;
        int l = findMAX(left, mid, ql, qr, 2 * index + 1);
        int r = findMAX(mid + 1, right, ql, qr, 2 * index + 2);
        return max(l, r);
    }
    int findSUM(int left, int right, int ql, int qr, int index)
    {
        if (left >= ql && right <= qr)
        {
            return tree[index];
        }
        if (ql > right || qr < left)
            return 0;
        int mid = (left + right) / 2;
        int l = findSUM(left, mid, ql, qr, 2 * index + 1);
        int r = findSUM(mid + 1, right, ql, qr, 2 * index + 2);

        return (l + r);
    }

public:
    // class constructor
    segmentTree(vector<int> &arr)
    {
        n = arr.size();
        // size of the segment tree that is to be allocated in 4*n = 2^(ceil(log2(n)) + 1 ) - 1  ............ i.e. 2^(h+1) - 1;
        int tree_size = 4 * n;
        tree.resize(tree_size);
        // buildMAXTree(arr, 0, n - 1, 0);
        buildSUMTree(arr, 0, n - 1, 0);
    }

    int giveMax(int ql, int qr)
    {
        if (ql < 0 || qr >= n || ql > qr)
            return INT_MIN;
        return findMAX(0, n - 1, ql, qr, 0);
    }

    int giveSum(int ql, int qr)
    {
        if (ql < 0 || qr >= n || ql > qr)
            return INT_MIN;

        return findSUM(0, n - 1, ql, qr, 0);
    }
};
int main()
{
    vector<int> a = {4, 1, 2, 2, 3, 1, 4, 6, 7, 8, 1, 2, 5, 8, 1, 0};
    segmentTree hehe(a);
    vector<vector<int>> querry = {{1, 5}, {2, 7}, {0, 15}, {5, 14}};
    for (auto it : querry)
    {
        int ql = it[0];
        int qr = it[1];
        cout << hehe.giveSum(ql, qr) << endl;
    }
    return 0;
}