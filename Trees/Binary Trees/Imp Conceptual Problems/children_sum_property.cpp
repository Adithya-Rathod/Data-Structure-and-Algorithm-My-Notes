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

void childrenSum(TreeNode<int> * &root)
{
    if(!root) return;

    int child =0;
    if(root->left) child+= root->left->val;
    if(root->right) child+= root->right->val;

    if(child>=root->val) root->val = child;
    else
    {
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    int tot =0;
    if(root->left) tot += root->left->val;
    if(root->right) tot += root->right->val;
    if(root->left || root->right) root->val = tot;
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
    
    childrenSum(t);
    levelOrder(t);
    return 0;

}