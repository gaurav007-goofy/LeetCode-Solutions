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
    vector<int>v;
    int num = 0;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        num  = num*10 + root->val;
        if(!root->left && !root->right)
        {
            v.push_back(num);
        }
        dfs(root->left); 
        dfs(root->right);
        
        num  =num/10;
    }
    int sumNumbers(TreeNode* root) {
        
        v.clear();
        
        dfs(root);
        
        int total = 0;
        for(auto num:v)
        {
            total += num;
        }
        return total;
    }
};