class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char c : s) mp[c]++;
        int odd_count = 0, even_sum = 0;
        for (auto pair : mp) {
            if (pair.second % 2 == 0)
                even_sum += pair.second;
            else {
                even_sum += pair.second - 1;
                odd_count++;
            }
        }
        if (odd_count)
            even_sum++;
        return even_sum;
    }
};