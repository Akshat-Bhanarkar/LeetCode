class Solution {
public:
    static bool compare(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second)
            return a.first<b.first;
        
        return a.second>b.second;
    }
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mpp;
        
        for(char c:s){
            mpp[c]++;
        }
        vector<pair<char, int>> freq(mpp.begin(), mpp.end());
        sort(freq.begin(),freq.end(),compare);    
        for (auto& p : freq) {
            ans += string(p.second, p.first);  
        }

        return ans;        
    }
};