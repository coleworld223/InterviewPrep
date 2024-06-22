/*
    Solution 1 : 
    There can be a DP solution -> 
    dp[i][j] = is subarray [i, i + 1, ... , j] a palindrome
    dp[i][j] = dp[i + 1][j - 1] (transitions)

    T.C. -> O (N * N), S.C -> O (N * N) (space can be optimised to O (1))


    Solution 2 :
    Manacher's Algorithm
    You can find a detailed blog on CP Algorithms
    Below implemented is Manacher's Algo

    T.C -> O (N)
    S.C -> O (N)
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector <int> d (2 * n + 1);
        string s1 = "$";
        for (int i = 0; i < n; i += 1) {
            s1.push_back(s[i]);
            s1.push_back('$');
        }
        int mx = 0;
        for (int i = 0, l = -1, r = -1; i < 2 * n + 1; i += 1) {
            if (i <= r) {
                d[i] = min (r - i, d[l + (r - i)]);
            }
            while (i + d[i] < 2 * n + 1 && i - d[i] >= 0) {
                if (s1[i + d[i]] == s1[i - d[i]]) d[i] += 1;
                else break;
            }
            if (i % 2 == 0) {
                mx = max (mx, (d[i] / 2) * 2);
            }
            else {
                mx = max (mx, 1 + ((d[i] - 1) / 2) * 2);
            }
            if (i + d[i] > r) {
                l = i - d[i] + 1, r = i + d[i] - 1;
            }
        }
        for (int i = 0; i < 2 * n + 1; i += 1) {
            if (i % 2 == 0 && (d[i] / 2) * 2 == mx) {
                string res = "";
                for (int x = i - d[i] + 1; x < i + d[i]; x += 1) {
                    if (s1[x] != '$') res.push_back(s1[x]);
                }
                return res;
            }
            if (i % 2 == 1 && (((d[i] - 1) / 2) * 2) + 1 == mx) {
                string res = "";
                for (int x = i - d[i] + 1; x < i + d[i]; x += 1) {
                    if (s1[x] != '$') res.push_back(s1[x]);
                }
                return res;
            }
        }
        return "";
    }
};