#include<iostream>
using namespace std;
 typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        val= data;
        left= right = NULL;
    }
 } TreeNode;
// TreeNode* insert(TreeNode* root, int val)
// {
//     // TreeNode* abhika = (TreeNode*)malloc(sizeof(TreeNode));
//     TreeNode* abhika = new TreeNode(val);
//     TreeNode* dummy = root;
//     if(!dummy)
//     {
//         dummy = abhika;
//         return;
//     }
//     else
//     {

//     }
     
// }   
int height(TreeNode* root, int &diame)
{
    if(root==NULL) return 0;
    else
    {
        int lh = height(root->left, diame);
        int rh = height(root->right, diame);
        diame= lh + rh;
        return max(lh, rh)+1;
    }
}
 int diameter(TreeNode *root)
 {
    int diam =0;
    height(root, diam);
    return diam;
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
     t->right->right->left = new TreeNode(10);
     t->right->right->left->right= new TreeNode(10);
     t->right->right->left->right->left = new TreeNode(10);
     t->right->right->left->right->left->right = new TreeNode(10);
     cout<<diameter(t);
return 0;
}