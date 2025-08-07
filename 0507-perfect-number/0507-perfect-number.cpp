class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>a;
        int n=0;
        for(int i=1;i<num;i++){
            if(num%i==0){
                a.push_back(i);
            }
        }
        for(int i=0;i<a.size();i++){
            n+=a[i];
        } 
        if(n==num){
            return true;
        }
        return false;   
    }
};