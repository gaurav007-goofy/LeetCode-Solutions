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
    vector<TreeNode*> totTrees(int l,int r){
        vector<TreeNode*> trees;
        if(l>r){
            trees.push_back(NULL);
            return trees;
        }
        for(int i=l;i<=r;i++){
            vector<TreeNode*> leftsub=totTrees(l,i-1);
            vector<TreeNode*> rightsub=totTrees(i+1,r);
            for(int j=0;j<leftsub.size();j++){
                TreeNode* lefts=leftsub[j];
                for(int k=0;k<rightsub.size();k++){
                    TreeNode* rights=rightsub[k];
                    TreeNode* root = new TreeNode(i);
                    root->left=lefts;
                    root->right=rights;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return totTrees(1,n);
    }
};