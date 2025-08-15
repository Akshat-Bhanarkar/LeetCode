class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> mp;
        string s = "";

        for (int i = 0; i < paragraph.size(); i++) {
            if ((paragraph[i] >= 'a' && paragraph[i] <= 'z') || (paragraph[i] >= 'A' && paragraph[i] <= 'Z')) {
                s.push_back(tolower(paragraph[i]));
            } else if (!s.empty()) {
                mp[s]++;
                s = "";
            }
        }

        if (!s.empty()) {
            mp[s]++;
        }

        for (auto i : banned) {
            mp[i] = 0;
        }

        int ans = 0;
        string fans = "";
        for (auto i : mp) {
            if (ans < i.second) {
                ans = i.second;
                fans = i.first;
            }
        }
        return fans;
    }
};