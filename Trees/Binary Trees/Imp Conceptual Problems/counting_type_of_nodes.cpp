#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        val = data;
        left =right =NULL;
    }
}; 
class Tree
{
    public:
    int maxLeaves(TreeNode * root)
    {   
        if(!root) return 0;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            int cnt{0};
            while(!q.empty())
            {
                root = q.front();
                q.pop();
                if(!root->left && !root->right)
                    cnt++;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            return cnt;
        }
    }
    int nonLeaves(TreeNode* root)
    {
        if(!root) return 0;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            int cnt{0};
            while(!q.empty())
            {
                root = q.front();
                q.pop();
                if(root->left || root->right)
                    cnt++;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            return cnt;
        }
    }
    int oneChild(TreeNode *root)
    {
        if(!root) return 0;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            int cnt{0};
            while(!q.empty())
            {
                root = q.front();
                q.pop();
             if((root->left)&&(!root->right)  || (root->right)&&(!root->left))
                    //if(root->left ^ root->right)   
                    cnt++;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            return cnt;
        }
    }
     TreeNode* findDeepest(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *curr;
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
        }
    return curr;
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
     t->right->right = new TreeNode(-1);
     t->right->right->left = new TreeNode(2);
     t->right->right->left->right= new TreeNode(-13);
     t->right->right->left->right->left = new TreeNode(22);
     t->right->right->left->right->left->right = new TreeNode(69);
    Tree jk;
    cout<<jk.maxLeaves(t)<<endl;
    cout<<jk.nonLeaves(t)<<endl;
    cout<<jk.oneChild(t)<<endl;
    cout<<jk.findDeepest(t)->val<<endl;
return 0;
}
/*
JHAAD
                  4
                /   \
               5     7
              / \  /  \ 
             6  9  1  -1        
                       /
                      2
                      \ 
                      -13
                       /
                      27
                       \
                       69

*/
