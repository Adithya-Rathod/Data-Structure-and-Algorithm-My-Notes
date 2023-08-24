#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template <typename T>
struct TreeNode
{
    T val;
    TreeNode* left, *right;
    TreeNode(T data)
    {
        val = data;
        left = right = NULL;
    }
};


TreeNode<int>* LCA(TreeNode<int> *root, TreeNode<int> *p,TreeNode<int> *q )
{
    if(!root || root==p ||root==q)
    {
        return root;
    }
    else
    {
        TreeNode<int>*l  = LCA(root->left, p, q);
        TreeNode<int>*r  = LCA(root->right, p, q);

        if(!l)  return r;
        else if(!r) return l;
        else return root;
    }

}

void levelOrder(TreeNode<int> *root)
{
    if(!root) return;
    else{
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            cout<<q.front()->val <<" ";
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }
}
int main()
{
    TreeNode<int> *t;
    t= new TreeNode<int>(2);
    t->left= new TreeNode<int>(3);
    t->right= new TreeNode<int>(5);
    t->left->left= new TreeNode<int>(4);
    t->left->right= new TreeNode<int>(6);
    t->right->left= new TreeNode<int>(7);
    t->right->right= new TreeNode<int>(10);
    
    TreeNode<int> *p =  t->left;
    TreeNode<int> *q =  t->left->left;
    cout<<LCA(t, p, q)->val;
    // levelOrder(t);
    return 0;

}