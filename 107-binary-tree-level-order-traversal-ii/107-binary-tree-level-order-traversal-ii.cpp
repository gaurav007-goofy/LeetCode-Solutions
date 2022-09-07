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
    int depth(TreeNode *root) {
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)
            return {};
        
        int level = depth(root);
        
        vector<vector<int>>ans(level);
    
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            vector<int>v;
            for(int i=0;i<len;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right); 
            }
            ans[level-1] = v;
            level--;
        }
        
        return ans;
    }
};