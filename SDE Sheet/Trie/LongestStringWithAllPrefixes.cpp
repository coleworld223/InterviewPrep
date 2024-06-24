#include <bits/stdc++.h>

struct node {
    node* nxt[26] = {NULL};
    int cntEnd = 0;
    int cntTill = 0;
};

class Trie{
    public:
    node* root;
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


string completeString(int n, vector<string> &a){
    Trie tree;
    for (int i = 0; i < n; i += 1) {
        tree.insert (a[i]);
    }

    string ans = "";

    for (int i = 0; i < n; i += 1) {
        node* cur = tree.root;
        string s = a[i];
        bool f = 1;
        for (int j = 0; j < (int) s.size(); j++) {
            char c = s[j] - 'a';
            if (!cur -> nxt[c]) {
                f = 0;
                break;
            }
            cur = cur -> nxt[c];
            if (cur -> cntEnd == 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            if (s.size() > ans.size()) ans = s;
            else if (s.size() == ans.size()) ans = min (ans, s);
        }
    }
    if (ans.empty()) ans = "None";
    return ans;
}