class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, n);
        int pos = -n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) pos = i;
            ans[i] = i - pos;
        }
        pos = 2 * n;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) pos = i;
            ans[i] = min(ans[i], pos - i);
        }
        return ans;
    }
};