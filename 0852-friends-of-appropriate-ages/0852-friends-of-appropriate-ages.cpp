class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int freq[121] = {0}, n = ages.size();
        for(int i = 0; i < n; ++i) ++freq[ages[i]];
        for(int i = 1; i < 121; ++i) freq[i] += freq[i - 1];
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(ages[i] < 15) continue;
            int low = 0.5 * ages[i] + 7;
            res += freq[ages[i]] - freq[low] - 1;
        }
        return res;
    }
};