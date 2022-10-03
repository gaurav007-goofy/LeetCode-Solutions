/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* getNext(Node* node)
    {
        node = node->next;
        while(node)
        {
            if(node->left)
                return node->left;
            if(node->right)
                return node->right;
            node = node->next;
        }
        
        return NULL;
    }
    
    void connectNode(Node *root)
    {
        if(!root)
            return;
        
        Node* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                if(curr->right)
                    curr->left->next = curr->right;
                else
                    curr->left->next = getNext(curr);
            }
            if(curr->right)
                curr->right->next = getNext(curr);
            
            curr = curr->next;
        }
        
        connectNode(root->left);
        connectNode(root->right);
    }
    
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        root->next = NULL;
        
        connectNode(root);
        return root;
    }
};