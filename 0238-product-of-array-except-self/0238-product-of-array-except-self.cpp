class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int prefix = 1, suffix = 1;

        for(int i = 0; i < nums.size(); i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};