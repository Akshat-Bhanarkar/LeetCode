class Solution {
public:
    double dfs(vector<vector<double>>& dp, vector<int>& nums, int k, int i) {
        // reached all elements
        if (i >= nums.size()) return 0;
        // cannot further partition
        if (k == 0) return INT_MIN;
        // the result has been calculated before
        if (dp[i][k] != -1) return dp[i][k];
        double mx = INT_MIN, sum = 0;
        for (int j = i; j < nums.size(); j++) {
            // sum from nums[i .. j]
            sum += nums[j];
            // current partition + the best result starting from the next index
            mx = max(mx, sum / (j - i + 1) + dfs(dp, nums, k - 1, j + 1));
        }
        // memorise the result
        return dp[i][k] = mx;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        // The best score partitioning A[i:] into at most K parts
        vector<vector<double>> dp(n, vector<double>(k + 1, -1));
        // starting from index 0
        return dfs(dp, nums, k, 0);
    }
};