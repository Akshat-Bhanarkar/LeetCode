class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>result;
        result.push_back(1);
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]) result.push_back(1);
            else result.back()++;
        }
        int ans=0;
        for(int i=0;i<result.size()-1;i++){
            ans+=min(result[i],result[i+1]);
        }
        return ans;
    }
};