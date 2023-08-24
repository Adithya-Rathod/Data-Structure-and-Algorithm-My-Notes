#include <bits/stdc++.h>
using namespace std;
//Recurssive 
// O(n) space and time complexity
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
    bool searchRecurssively(Node *current, int val)
    {
        if(current == NULL)
            return 0;
        if(current->data == val)
            return 1;
        
        bool left = searchRecurssively(current->left, val);
        if(left)
            return true;
        
        bool right = searchRecurssively(current->right, val);
        if(right)
            return true;

        return false;
    }

    Tree()
    {
        root = NULL;
    }

    bool search(int val)
    {
        return searchRecurssively(root, val);
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

    cout<< t.search(0);
    return 0;
}