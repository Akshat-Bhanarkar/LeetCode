class Solution {
public:
    static int maximumUniqueSubarray(vector<int>& nums) {
        const int n=nums.size();
        bitset<10001> hasX=0;
        int ans=0, wsum=0;

        for (int l=0, r=0; r<n; r++) {
            const int x=nums[r];
            while (hasX[x]) {
                hasX[nums[l]]=0;
                wsum-=nums[l];
                l++;
            }
            hasX[x]=1;
            wsum+=x;
            ans=max(ans, wsum);
        }
        return ans;
    }
};