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
    TreeNode* prev = NULL;
    int ans = INT_MAX;
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->left)
            solve(root->left);
        
        if(prev!=NULL)
        {
            ans = min(ans, abs(prev->val-root->val));
        }
        prev = root;
        
        if(root->right)
            solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        
        solve(root);
        return ans;
    }
};