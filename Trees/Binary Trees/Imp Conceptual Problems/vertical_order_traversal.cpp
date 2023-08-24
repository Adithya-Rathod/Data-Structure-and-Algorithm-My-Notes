#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        data=val;
        left =right = NULL;
    }
};

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    if(!root) return {};
    else
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        // vertical -> (level -> data )
        queue<pair<TreeNode* , pair<int,int>>> q;
        // {node, {vertical, level}};
        q.push({root,{0,0}});
        while(!q.empty())
        {
            root = q.front().first;
            q.pop();
            int vertical = q.front().second.first;
            int level = q.front().second.second;

            nodes[vertical][level].insert(root->data);

            if(root->left) q.push({root->left, {vertical-1, level+1}});
            if(root->right) q.push({root->right, {vertical+1, level+1}});
        }

        for(auto i : nodes)
        {
            vector<int> temp;
            for(auto j : i.second)
            {
                temp.insert(temp.begin(), j.second. begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;

    }
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
  
  vector<vector<int>> ans = verticalTraversal(root);
  for(auto i : ans)
  {
    for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
  }
}