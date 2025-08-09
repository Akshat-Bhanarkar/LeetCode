class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++){
            int n = i;
            int flag = true;
            while(n>0){
                int rem = n%10;
                if(rem==0) flag = false; 
                else if(i%rem != 0) flag = false;
                n /= 10;
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};