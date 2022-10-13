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
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        v.clear();
        solve(root);
        
        int ans = INT_MAX;
        
        for(int i=1;i<v.size();i++)
        {
            ans = min(ans,abs(v[i-1]-v[i]));
        }
        return ans;
    }
};