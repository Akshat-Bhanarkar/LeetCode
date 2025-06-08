class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<string> vct;
        for(int i = 1 ; i <= n ; i++)
        {
            vct.push_back(to_string(i));
        }    
        sort(vct.begin() , vct.end());

        vector<int> ans;
        for(auto each : vct)
        {
            ans.push_back(stoi(each));
        }  

        return ans;
    }
};