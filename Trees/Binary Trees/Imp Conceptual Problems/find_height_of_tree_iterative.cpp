#include <bits/stdc++.h>
using namespace std;
// simple Binary tree with{Complete binary tree though}
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
    int sizeOf(node *curr)
    {
        if (curr == nullptr)
            return 0;
        return sizeOf(curr->left) + 1 + sizeOf(curr->right);
    }

public:
    Tree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        node *newnode = new node(value);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        // inserting using level order beacuse it is just a binary tree no hard feelings and rules :>
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            else
            {
                curr->left = newnode;
                return;
            }
            if (curr->right)
                q.push(curr->right);
            else
            {
                curr->right = newnode;
                return;
            }
        }
    }

    void levelOrder()
    {
        // print all the nodes at level l and use a queue to store the nodes at level l+1
        if (root == NULL)
            return;
        node *curr = root;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    int size()
    {
        return sizeOf(root);
    }

   int getHeight() {
    if (root == nullptr) {
        return 0;  // Empty tree has height 0
    }

    int height = 0;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        // Process nodes at the current level
        while (levelSize > 0) {
            node* curr = q.front();
            q.pop();

            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }

            levelSize--;
        }

        // Check if there are more levels to process
        if (!q.empty()) {
            height++;  // Move to the next level
        }
    }

    return height +1;
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

    t1.levelOrder();

    cout<<endl<<t1.getHeight();
    Tree t2;
    t2.insert(1);
    t2.insert(1);
    t2.insert(1);
    cout<<endl<<t2.getHeight();
    return 0;
}