#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
 struct TreeNode
 {
    int val;
    TreeNode* left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
 };
 class Traversal{
    public:
        vector<int> morrisInorder(TreeNode *root)
        {
            vector<int> inorder;
            TreeNode* curr= root;
            while(curr!=NULL)
            {
                //case1
                if(curr->left ==NULL)
                {
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }

                else
                {
                    TreeNode*prev = curr->left;
                    //going to the right most child in the left subtree
                    while(prev->right && prev->right != curr)
                    {   
                        prev = prev->right;
                    }
                    //when we reach to the right most child and create a thread
                    if(prev->right == NULL)
                    {
                        prev->right = curr;
                        curr = curr->left;
                    }
                    //if there exist a thread to the curr that means we have to remove the thread and go to the right subtree 
                    else
                    {
                        prev->right= NULL;
                        inorder.push_back(curr->val);
                        curr= curr->right;
                    }
                }
            }
            return inorder;
        }

        vector<int> morrisPreorder(TreeNode *root)
        {
            vector<int> preorder;
            TreeNode* curr= root;
            while(curr!=NULL)
            {
                //case1
                if(curr->left ==NULL)
                {
                    preorder.push_back(curr->val);
                    curr = curr->right;
                }

                else
                {
                    TreeNode*prev = curr->left;
                    //going to the right most child in the left subtree
                    while(prev->right && prev->right != curr)
                    {   
                        prev = prev->right;
                    }
                    //when we reach to the right most child and create a thread and also since preorder tab hich kardo root print 
                    if(prev->right == NULL)
                    {
                        prev->right = curr;
                        preorder.push_back(curr->val);
                        curr = curr->left;
                    }
                    //if there exist a thread to the curr that means we have to remove the thread and go to the right subtree 
                    else
                    {
                        prev->right= NULL;
                        curr= curr->right;
                    }
                }
            }
            return preorder;
        }

 };
int main()
{
 
return 0;
}