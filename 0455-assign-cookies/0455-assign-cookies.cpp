class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int ans=0;
        int i=0,j=0;
        int m=g.size(),n=s.size();
        while(i<m && j<n){
            if(g[i]<=s[j]){
                ans++;
                i++,j++;
            }
            else j++;
        }
        return ans;
    }
};