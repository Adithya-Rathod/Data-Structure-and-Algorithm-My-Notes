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
    void insert(node *current, int value)
    {
        if(current == NULL) 
        {
            current =  new node(value);
            return;
        }
        queue<node*> q;
        q.push(current);
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            if(current->left)
               q.push(current->left);
            else
            {
                current->left = new node(value);
                return;
            } 
            if(current->right)
                q.push(current->right);
            else
            {
                current->right = new node(value);
                return;
            }
        }
    }
     void preorder(node *curr)
    {
        if (curr!=NULL)
        {
            cout << curr->data << " ";
            preorder(curr->left);
            preorder(curr->right);
        }
    }
    void preorderIter(node *curr)
    {
        stack<node*> st;
        while(1)
        {
            while(curr)
            {
                cout<<curr->data<<" ";
                st.push(curr);
                curr= curr->left;
            }
            if(st.empty())
                return;
            curr = st.top();
            st.pop();
            curr= curr->right;

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

        insert(root, value);
    }

    void diplayPreorder()
    {
        preorder(root);
        // preorderIter(root);

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
    t1.diplayPreorder(); 
    return 0;
}