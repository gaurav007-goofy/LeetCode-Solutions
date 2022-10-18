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
    vector<int>res;
    void solve(TreeNode* root,int level)
    {
        if(!root)
            return;
        if(res.size()==level)    // to push only rightmost element
            res.push_back(root->val);
        
        solve(root->right,level+1);
        solve(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        solve(root,0);
        
        return res;
        
        // level-order traversal
//         if(!root)
//             return {};
//         vector<int>ans;
        
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty())
//         {
//             int len = q.size();
//             for(int i=0;i<len;i++)
//             {
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if(i==len-1)
//                     ans.push_back(temp->val);
                
//                 if(temp->left)
//                     q.push(temp->left);
//                 if(temp->right)
//                     q.push(temp->right);
//             }
//         }
        
//         return ans;
    }
};