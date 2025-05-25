class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration;
        for(int i = 1, n = timeSeries.size(); i < n; ++i){ 
            int gap = timeSeries[i] - timeSeries[i - 1];
            total += min(gap , duration);
        }
        return total;
    }
};