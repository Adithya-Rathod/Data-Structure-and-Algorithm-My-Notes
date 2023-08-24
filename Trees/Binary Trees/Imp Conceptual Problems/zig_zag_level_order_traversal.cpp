#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int dat)
    {
        val = dat;
        left = right = NULL;
    }
    /* data */
};
vector<vector<int>> zigzag(TreeNode* root)
{
    if(!root) return{};
    else
    {
        vector<int> temp;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int lvl= q.size();
            while(lvl--)
            {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(leftToRight)
                ans.push_back(temp);
            else
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            leftToRight = !leftToRight;
            temp.clear();
        }
        return ans;
    }
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
     t->right->right->left = new TreeNode(12);
     t->right->right->right= new TreeNode(14);
     t->right->right->left->left = new TreeNode(21);
     t->right->right->left->right = new TreeNode(18);
     vector<vector<int>> res = zigzag(t);
     for(auto it : res)
        {
            for(auto j :it)
                cout<<j<<" ";;
            cout<<endl;
        }
}
/*
           4
          / \
         5   7
        / \   \
       6   9   10
              / \
             12  14
            / \
           21  18
*/