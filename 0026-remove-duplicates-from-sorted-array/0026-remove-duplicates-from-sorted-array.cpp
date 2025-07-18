class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size(),count=1;
       if(n==0){return 0;}

       for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            nums[count]=nums[i];
            count++;
        }
       }
    return count;
}
};