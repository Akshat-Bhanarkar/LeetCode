class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int n = nums.size();
      int count=0;
      int maxCount =0;
      for(int i=0; i < n;i++){
          if(nums[i] == 1){
            count ++ ;
            maxCount = max(count , maxCount);
          }
          else{
            count = 0;
          }
      }  
      return maxCount;
    }
};