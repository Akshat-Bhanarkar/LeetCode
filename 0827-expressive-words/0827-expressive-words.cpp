class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (int i = 0, n = words.size(); i < n; ++i) {
            if (isStretchy(s, words[i])) ++res;
        }
        return res;
    }
    bool isStretchy(const string& s, const string& w) {
        int i = 0, j = 0, n = s.length(), m = w.length();
        while (i < n && j < m) {
            if (s[i] != w[j]) return false;
            int len1 = 1, len2 = 1;
            while (i + len1 < n && s[i + len1] == s[i]) ++len1;
            while (j + len2 < m && w[j + len2] == w[j]) ++len2;
            if (len1 < len2) return false;
            if (len1 != len2 && len1 < 3) return false;
            i += len1;
            j += len2;
        }
        return i == n && j == m;
    }
};