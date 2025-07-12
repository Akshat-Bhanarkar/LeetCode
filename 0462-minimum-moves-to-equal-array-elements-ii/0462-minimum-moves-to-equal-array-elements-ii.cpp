class Solution {
public:
    int minMoves2(vector<int>& nums) {
       int n=nums.size(),sum=0;
       sort(nums.begin(),nums.end());
        int med = nums[n / 2];
       
    for(int i=0;i<n;i++){
        sum+=abs(med-nums[i]);
    }
    return sum;
    }
};