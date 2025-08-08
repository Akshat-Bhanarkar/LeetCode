class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> firstSeen;
        int degree = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (firstSeen.find(num) == firstSeen.end()) {
                firstSeen[num] = i;
            }
            count[num]++;
            if (count[num] > degree) {
                degree = count[num];
                minLength = i - firstSeen[num] + 1;
            } else if (count[num] == degree) {
                minLength = min(minLength, i - firstSeen[num] + 1);
            }
        }

        return minLength;
    }
};