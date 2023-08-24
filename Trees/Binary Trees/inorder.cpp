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
        left = NULL;
        right = NULL;
    }
};

class Tree
{
private:
    node *root;
    int size;
    void insertRecursive(node *current, int value)
    {
        if (current->left == nullptr)
        {
            current->left = new node(value);
        }
        else if (current->right == nullptr)
        {
            current->right = new node(value);
        }
        else
        {
            //If both left and right child exist, go deeper on the left side
            insertRecursive(current->left, value);
        }
    }
     void inorder(node *curr)
    {
        if (curr!=NULL)
        {
            inorder(curr->left);
            cout << curr->data << " ";
            inorder(curr->right);
        }
    }
public:
    Tree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        if (root == nullptr)
        {
            root = new node(value);
            return;
        }

        insertRecursive(root, value);
    }

    void diplayInorder()
    {
        inorder(root);
    }

    void levelOrder()
    {
        if(root==NULL)
            return;
        node *curr = root;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            curr = q.front();
            cout<<curr->data<<" ";
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        } 

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
    t1.insert(8);
    t1.diplayInorder(); 
    return 0;
}