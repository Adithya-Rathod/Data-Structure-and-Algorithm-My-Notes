#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        left = right = nullptr;
        val = data;
    }
};

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}

void leftBoundary(TreeNode *root, vector<int> &traversal)
{

        root = root->left;
        while (root)
        {
            if (!isLeaf(root))
                traversal.push_back(root->val);
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
    
}

void rightboundary(TreeNode *root, vector<int> &traversal)
{

        vector<int> temp;
        root = root->right;
        while (root)
        {
            if (!isLeaf(root))
                temp.push_back(root->val);
            if (root->right)
                root = root->right;
            else
                root = root->left;
        }
        while (!temp.empty())
        {
            traversal.push_back(temp.back());
            temp.pop_back();
        }

}

void leafBoundary(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->val);
        return;
    }
    if (root->left)
        leafBoundary(root->left, res);
    if (root->right)
        leafBoundary(root->right, res);
}
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> traversal;
    if (!root)
        return traversal;
    if (!isLeaf(root))
        traversal.push_back(root->val);

    // part 1:
        leftBoundary(root, traversal);

    // part 2:
        leafBoundary(root, traversal);

    // part 3:
        rightboundary(root, traversal);

        return traversal;
}

int main()
{
    TreeNode *root = new TreeNode(100);
  root -> left = new TreeNode(2);
  root -> left -> left = new TreeNode(3);
  root -> left -> left -> right = new TreeNode(4);
  root -> left -> left -> right -> left = new TreeNode(5);
  root -> left -> left -> right -> right = new TreeNode(6);
  root -> right = new TreeNode(7);
  root -> right -> right = new TreeNode(8);
  root -> right -> right -> left = new TreeNode(9);
  root -> right -> right -> left -> left = new TreeNode(10);
  root -> right -> right -> left -> right = new TreeNode(11);
  
    vector<int> ans = boundaryTraversal(root);
    for(auto it: ans)
        cout<<it<<" ";
}