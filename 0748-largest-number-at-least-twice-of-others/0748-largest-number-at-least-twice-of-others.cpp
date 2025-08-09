class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // store maximum value and its index from `nums`
        int maxVal = -1, maxId = -1;

        // step 1 - iterate on `nums` find maximum number and its index
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxId = i;
            }
        }

        // step 2 - check given condition while iterating on each number of `nums`
        for (int i = 0; i < nums.size(); i++) {
            if (i == maxId) continue;

            // step 3 - if the largest element in the array is not at least twice as much as
            // every other number, return -1 immdeiately
            if (maxVal < 2 * nums[i]) {
                return -1;
            }
        }

        // step 4 - otherwise return maximum value index `maxId`
        return maxId;
    }
};