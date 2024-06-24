#include <bits/stdc++.h> 
struct node {
    node* nxt[26] = {NULL};
    int cntEnd = 0;
    int cntTill = 0;
};

class Trie{
    node* root;
    public:

    Trie(){
        root = new node();
    }

    void insert(string &word){
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i += 1) {
            char c = word[i] - 'a';
            if (!cur -> nxt[c]) cur -> nxt[c] = new node();
            cur = cur -> nxt[c];
            cur -> cntTill++;
        }
        cur -> cntEnd++;
    }

    int countWordsEqualTo(string &word){
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i++) {
            char c = word[i] - 'a';
            if (!cur -> nxt[c]) return 0;
            cur = cur -> nxt[c];
        }
        return cur -> cntEnd;
    }

    int countWordsStartingWith(string &word){
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i++) {
            char c = word[i] - 'a';
            if (!cur -> nxt[c]) return 0;
            cur = cur -> nxt[c];
        }
        return cur -> cntTill;
    }

    void erase(string &word){
        node* cur = root;
        for (int i = 0; i < (int) word.size(); i++) {
            char c = word[i] - 'a';
            cur = cur -> nxt[c];
            cur -> cntTill--;
        }
        cur -> cntEnd--;
    }
};
