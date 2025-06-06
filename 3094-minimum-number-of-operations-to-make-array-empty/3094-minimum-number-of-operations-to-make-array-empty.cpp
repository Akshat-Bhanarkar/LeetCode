class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }

        int ans = 0;

        for (auto [x, f] : mp) {
            if (f == 1)
                return -1;
            ans += ceil(double(f) / 3);
        }

        return ans;
    }
};