/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = INT_MIN;
    void solve(Node* root,int depth)
    {
        if(!root)
            return;
        ans = max(ans,depth);
        
        for(int i=0;i<root->children.size();i++)
        {
            solve(root->children[i],depth+1);  // don't use depth++ ;
        }
    }
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        solve(root,1);
        
        return ans;
    }
};