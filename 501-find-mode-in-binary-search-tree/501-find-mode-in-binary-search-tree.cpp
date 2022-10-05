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
    unordered_map<int,int>mp;
    
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return {};
        mp.clear();
        
        dfs(root);
        
        vector<int>ans;
        
        int maxx =INT_MIN;
        for(auto it:mp)
        {
            maxx = max(maxx,it.second);
        }
        for(auto it:mp)
        {
            if(it.second==maxx)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};