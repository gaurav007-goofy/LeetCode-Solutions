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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void recoverTree(TreeNode* root) {
        dfs(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        if(!first && prev && prev->val >= root->val){
            first = prev;
        }
        if(first && prev && prev->val >= root->val){
            second = root;
        }
        prev = root;
        dfs(root->right);
    }
};