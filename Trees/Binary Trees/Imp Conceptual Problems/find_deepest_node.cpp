#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Tree
{
    node *root;

    void Inorder(node *curr)
    {
        if(curr==NULL)
            return;
        Inorder(curr->left);
        cout<<curr->data;
        Inorder(curr->right);
    }
    void Postorder(node *curr)
    {
        if(curr==NULL)
            return;
        Postorder(curr->left);
        Postorder(curr->right);
        cout<<curr->data;
    }
    void Preorder(node *curr)
    {
        if(curr==NULL)
            return;
        cout<<curr->data;
        Preorder(curr->left);
        Preorder(curr->right);
    }
public:
    Tree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        node *newnode = new node(val);
        if(root==NULL)
            {
                root = newnode;
                return;
            }
        queue<node *> q;
        q.push(root);
        while(!q.empty())
        {
            node *curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            else
            {
                curr->left = newnode;
                return;
            }
            if(curr->right)
                q.push(curr->right);
            else
            {
                curr->right = newnode;
                return;
            }
        }

    }
    void inorder()
    {
        Inorder(root);
    }
    void postorder()
    {
        Postorder(root);
    }
    void preorder()
    {
        Preorder(root);
    }
    int findDeepest()
    {
        if(root==NULL)
            return -1;
        queue<node*> q;
        q.push(root);
        node *curr;
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
        }
    return curr->data;
    }
};

int main()
{
     Tree t1;
    t1.insert(1);
    t1.insert(2);
    t1.insert(5);
    t1.insert(4);
    t1.insert(3);
    t1.insert(10);
    t1.insert(9);

    cout<<t1.findDeepest();
    return 0;
}