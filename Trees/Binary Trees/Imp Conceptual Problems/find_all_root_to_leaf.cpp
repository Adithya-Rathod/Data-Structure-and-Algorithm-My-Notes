#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 struct TreeNode
 {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int dat)
    {
        dat = val;
        left = right = NULL;
    }
 };
 class Tree
 {
    public:
    void root_to_leaf(TreeNode* root, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(!root) return;
        temp.push_back(root->val);

        if(!root->left && !root->right)
        {
            ans.push_back(temp);
            temp.clear();
        }
        else
        {
            root_to_leaf(root->left, temp, ans);
            root_to_leaf(root->right,temp, ans);
        }
    }
 };
int main()
{
  TreeNode* t;
     t = new TreeNode(4);
     t->left = new TreeNode(5);
     t->right = new TreeNode(7);
     t->left->left = new TreeNode(6);
     t->left->right = new TreeNode(9);
     t->right->left = new TreeNode(1);
     t->right->right = new TreeNode(10);
     t->right->right->left = new TreeNode(10);
     t->right->right->left->right= new TreeNode(10);
     t->right->right->left->right->left = new TreeNode(10);
     t->right->right->left->right->left->right = new TreeNode(10);
     Tree jk;
     vector<int> temp;
     vector<vector<int>> ans;
     jk.root_to_leaf(t, temp, ans);
     for(auto i : ans)
     {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
        }
return 0;
}