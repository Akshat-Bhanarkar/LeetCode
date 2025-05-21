class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total + target) % 2 != 0 || total < abs(target)) return 0;

        int sum = (total + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[sum];
    }
};