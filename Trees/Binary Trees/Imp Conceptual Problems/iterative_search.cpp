#include <bits/stdc++.h>
using namespace std;
// Iterative searching operation by using level order traversal
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

    bool search(int val)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
                return false;
            if (temp->data == val)
                return true;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return false;
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

    cout << t.search(9);
    return 0;
}