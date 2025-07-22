class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> M;
        for (char c : s)
            M[c]++;
        
        stack<char> S;
        vector<bool> visited(26, 0);
        string ans = "";

        for (char c : s) {
            if (!visited[c - 'a']) {
                while (!S.empty() && S.top() > c) {
                    if (M[S.top()] != 0) {
                        visited[S.top() - 'a'] = 0;
                        S.pop();
                    } else break;
                }
                S.push(c);
                visited[c - 'a'] = 1;
            }
            M[c]--;
        }

        while (!S.empty()) {
            ans.push_back(S.top());
            S.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};