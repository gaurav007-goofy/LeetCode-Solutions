class TrieNode{
public :
    
    TrieNode * childs[26];
    bool flag = false;
    
    TrieNode(){
        for(int i = 0; i <26; i++)
            childs[i] = NULL;
    }
    
    bool containKey(char ch)
    {
        return (childs[ch-'a'] != NULL);
    }
    void put(char ch,TrieNode* newNode)
    {
        childs[ch-'a'] = newNode;
    }
    
    TrieNode* get(char ch)
    {
        return childs[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto ch: word) {
            if(!node->containKey(ch))
                node->put(ch,new TrieNode());
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(auto ch: word) {
            if(!node->containKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto ch: prefix) {
            if(!node->containKey(ch))
                return false;
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */