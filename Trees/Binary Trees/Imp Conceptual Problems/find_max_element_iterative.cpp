#include <bits/stdc++.h>
using namespace std;
// Iteratively find the maximum for every node using level order traversal
//  O(n) space for queue DS and time complexity of O(N)
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Tree
{

public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    int findMax()
    {
        queue<Node *> q;
        q.push(root);
        int maxi =INT_MIN;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            maxi = max(maxi , temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return maxi;
    }
};
int main()
{
    Tree t;
    t.root = new Node(4);
    t.root->left = new Node(5);
    t.root->right = new Node(7);
    t.root->left->left = new Node(6);
    t.root->left->right = new Node(9);
    t.root->right->left = new Node(1);
    t.root->right->right = new Node(10);

    cout << t.findMax();
    return 0;
}