/*
    See Striver's tutorial for an explanation or read some blog from google
*/

struct node {
    node* nxt[26] = {NULL};
    int cntEnd = 0;
    int cntTill = 0;
};

class Trie {
private:
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i++) {
            char curChar = (word[i] - 'a');
            if (!cur -> nxt[curChar]) cur -> nxt[curChar] = new node();
            cur = cur -> nxt[curChar];
            cur -> cntTill++;
        }
        cur -> cntEnd++;
    }
    
    bool search(string word) {
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i++) {
            char curChar = word[i] - 'a';
            if (!cur -> nxt[curChar]) return false;
            cur = cur -> nxt[curChar];
        }
        return cur -> cntEnd;
    }
    
    bool startsWith(string prefix) {
        node* cur = root;
        for (int i = 0; i < (int) prefix.size(); i++) {
            char curChar = prefix[i] - 'a';
            if (!cur -> nxt[curChar]) return false;
            cur = cur -> nxt[curChar];
        }
        return cur -> cntTill;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */