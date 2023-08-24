#include <bits/stdc++.h>
using namespace std;
//Recurssive 
// O(n) space and time complexity
//find the maximum in left subtree rigth subtree and root recurssively
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
    int findd(Node *current)
    {
       int left , right, max = INT_MIN;
       if(current)
       {
        int temp = current->data;
        left  = findd(current->left);
        right = findd(current->right);
        if( right < left)
            max = left;
        else
            max = right;
        if(temp > max)
            max = temp;
       }
       return max;


    }

    Tree()
    {
        root = NULL;
    }

    int findMax()
    {
        return findd(root);
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

    cout<< t.findMax();
    return 0;
}