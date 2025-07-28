class Solution {
public:
    vector<int> tail; // Tail array to store OR of elements from index i to end
    int max_or;       // Maximum OR value
    vector<int> nums; // Reference to the input array

    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        max_or = nums[0];

        // Calculate maximum OR of all elements
        for (int i = 1; i < nums.size(); i++) {
            max_or |= nums[i];
        }

        // Populate the tail array
        tail.resize(nums.size());
        int v = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            v |= nums[i];
            tail[i] = v;
        }

        // Start the recursion
        return recurse(0, 0);
    }

    int recurse(int i, int partial) {
        // If partial OR equals max OR, return the number of remaining subsets
        if (partial == max_or) {
            return 1 << (nums.size() - i);
        }

        // If end of array is reached or can't achieve max OR, return 0
        if (i == nums.size() || ((partial | tail[i]) != max_or)) {
            return 0;
        }

        // Recursive step: include or exclude current element
        return recurse(i + 1, partial | nums[i]) + recurse(i + 1, partial);
    }
};