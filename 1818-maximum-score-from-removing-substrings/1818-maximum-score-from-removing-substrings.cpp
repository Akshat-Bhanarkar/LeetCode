class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto removePairs = [](string &s, string pair, int score) {
            int res = 0;
            string stk;
            for (char c : s) {
                if (!stk.empty() && c == pair[1] && stk.back() == pair[0]) {
                    stk.pop_back();
                    res += score;
                } else {
                    stk.push_back(c);
                }
            }
            s = stk;
            return res;
        };

        int res = 0;
        if (x > y) {
            res += removePairs(s, "ab", x);
            res += removePairs(s, "ba", y);
        } else {
            res += removePairs(s, "ba", y);
            res += removePairs(s, "ab", x);
        }
        return res;
    }
};