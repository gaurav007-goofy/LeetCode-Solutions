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
    int cnt =0;   // to store current count
    int prev = -1;  // to store prev element
    int max_count = INT_MIN;  // to store max count
    
    void solve(TreeNode* root,vector<int>& ans)
    {
        if(!root)
            return;
        
        solve(root->left,ans);    // left traversal
        
        if(root->val==prev)
            cnt++;
        else cnt = 1;
        
        prev = root->val;
        
        if(cnt> max_count)
        {
            max_count = cnt;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(cnt == max_count)
        {
            ans.push_back(root->val);
        }
        
        solve(root->right,ans);    // right traversal
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        
        return ans;
    }
};