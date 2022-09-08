/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>res;
    void dfs(TreeNode* root,int target,int sum,vector<int>temp)
    {
        if(!root)
            return;
        sum += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum==target)
        {
            res.push_back(temp);
            return;
        }
        dfs(root->left,target,sum,temp);
        dfs(root->right,target,sum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0,{});
        return res;
    }
};