class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto &w:words){
            mp[w]++;
        }
        vector<pair<int,string>>temp;
        for(auto it:mp){
            temp.push_back({it.second,it.first});
        }

        auto lambda=[&](pair<int,string>&p1,pair<int,string>&p2){
            if(p1.first==p2.first) return p1.second<p2.second;
            return p1.first>p2.first;
        };

        sort(temp.begin(),temp.end(),lambda);

        int i=0;
        vector<string>ans;
        while(i<k){
            ans.push_back(temp[i++].second);
        }
        return ans;
    }
};