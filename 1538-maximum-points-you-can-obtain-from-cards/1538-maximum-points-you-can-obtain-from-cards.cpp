class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for (int i = 0; i < k; ++i)
            total += cardPoints[i];

        int maxSum = total;

        for (int i = 0; i < k; ++i) {
            total -= cardPoints[k - 1 - i];         
            total += cardPoints[n - 1 - i];         
            maxSum = max(maxSum, total);
        }

        return maxSum;
    }
};