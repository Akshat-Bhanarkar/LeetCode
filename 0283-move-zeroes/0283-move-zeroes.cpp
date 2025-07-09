class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),index=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[index++]=nums[i];
            }
            }
            for (int i = index; i < n; i++) {
            nums[i] = 0;
        }
    }
};