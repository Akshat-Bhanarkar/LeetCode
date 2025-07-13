class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        for (int r = 0; r < s.size(); ++r) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};