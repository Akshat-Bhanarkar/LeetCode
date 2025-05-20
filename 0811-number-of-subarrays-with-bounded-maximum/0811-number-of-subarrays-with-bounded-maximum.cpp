class Solution {
public:
    int countSubarraysWithMaxAtMost(vector<int>& nums, int bound) {
        int count = 0, length = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= bound) {
                length++;
            } else {
                length = 0;
            }
            count += length;
        }

        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarraysWithMaxAtMost(nums, right) -
               countSubarraysWithMaxAtMost(nums, left - 1);
    }
};