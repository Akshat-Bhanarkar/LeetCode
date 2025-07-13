class Solution {
public:
    int recursion(vector<int>& nums,int i,int n,int x){
        if(i>=n)return 0;
        if(nums[i]>x){
            return max(1+recursion(nums,i+1,n,nums[i]),recursion(nums,i+1,n,x));
        }
        else{
            return recursion(nums,i+1,n,x);
        }
    }
    int dpMemo(vector<int>& nums, vector<vector<int>>& dp, int i, int prev,
               int n) {
        if (i >= n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int ans = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            ans = max(1 + dpMemo(nums, dp, i + 1, i, n),
                      dpMemo(nums, dp, i + 1, prev, n));
        } else {
            ans = dpMemo(nums, dp, i + 1, prev, n);
        }
        dp[i][prev + 1] = ans;
        return dp[i][prev + 1];
    }

    int dpTab(vector<int>& nums, vector<vector<int>>& dp, int n) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int include = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    include = 1 +dp[i + 1][i+1];
                }
                int exclude = dp[i + 1][j+1];
                dp[i][j + 1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int binarySearch(vector<int>& nums,int n){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums,n);
    }
};