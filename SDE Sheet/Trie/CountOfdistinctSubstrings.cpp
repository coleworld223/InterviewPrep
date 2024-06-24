#include <bits/stdc++.h> 
struct node {
    node* nxt[26] = {NULL};
    int cntEnd = 0;
    int cntTill = 0;
};

int countDistinctSubstrings(string &s)
{
    int ans = 0;
    node* root = new node();
    for (int i = 0; i < (int) s.size(); i++) {
        string tmp = "";
        node* cur = root;
        for (int j = i; j < s.size(); j++) {
            char c = s[j] - 'a';
            if (!cur -> nxt[c]) cur -> nxt[c] = new node();
            cur = cur -> nxt[c];
            cur -> cntEnd++;
            ans += (cur -> cntEnd == 1);
        }
    }
    ans += 1;
    return ans;
}