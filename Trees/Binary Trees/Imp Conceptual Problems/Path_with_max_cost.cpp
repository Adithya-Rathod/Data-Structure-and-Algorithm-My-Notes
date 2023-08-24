#include<iostream>
#include<limits.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
}; 
int arbitSum(TreeNode* root, int &maxi)
{
    if(!root) return 0;
    else
    {
        int left =max(0, arbitSum(root->left, maxi));
        int right = max(0, arbitSum(root->right, maxi));
        maxi = max(maxi, (left + right + root->val));
        return max(left, right) + root->val;
    }
}
int maxSum(TreeNode* root)
{
    //approach -> left subtrree mei max sum nikaalo and right subtree mei max sum nikaalo
    int maxi = INT_MIN;
    arbitSum(root, maxi);
    return maxi;
}
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
     t->right->right->left = new TreeNode(-1);
     t->right->right->left->right= new TreeNode(-13);
     t->right->right->left->right->left = new TreeNode(21);
     t->right->right->left->right->left->right = new TreeNode(-40);
     cout << maxSum(t);
return 0;
}