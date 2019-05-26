#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = 0;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    ~Trie() {
        for (int i = 0; i < _node_vec.size(); i++) {
            delete _node_vec[i];
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = &_root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (!ptr->child[pos]) {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = &_root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (!ptr->child[pos]) {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return ptr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = &_root;
        for (int i = 0; i < prefix.length(); i++) {
            int pos = prefix[i] - 'a';
            if (!ptr->child[pos]) {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return true;
    }
    
    TrieNode* root() {
        return &_root;
    }
private:
    TrieNode* new_node() {
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode *> _node_vec;
    TrieNode _root;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        _trie_tree.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_trie(_trie_tree.root(), word.c_str());
    }
    
    bool search_trie(TrieNode *node, const char *word) {
        if (*word == '\0') {
            return node->is_end;
        }
        if (*word == '.') {
            for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
                if (node->child[i] && search_trie(node->child[i], word + 1)) {
                    return true;
                }
            }
        } else {
            int pos = *word - 'a';
            if (node->child[pos] && search_trie(node->child[pos], word + 1)) {
                return true;
            }
        }
        return false;
    }
private:
    Trie _trie_tree;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
