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
    int ans =0;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left_sum =0,right_sum = 0;
        if(root->left)
            left_sum = root->left->val + solve(root->left);
        if(root->right)
            right_sum = root->right->val + solve(root->right);
        ans += abs(left_sum-right_sum);
        
        return (left_sum+right_sum);
    }
    int findTilt(TreeNode* root) {
        int x = solve(root);
        
        return ans;
    }
};