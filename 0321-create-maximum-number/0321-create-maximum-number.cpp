class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <int>res;

        for(int i = 0; i<=k; i++){
            vector <int> a = fun(nums1, i);
            vector <int> b = fun(nums2, k-i);

            vector <int> m;
            merge(a, b, m);

            if(m.size()==k) res = max(res,m);
        }
        return res;
    }
protected:
    // This function is the code of "Find most consecutive subsequence" problem, which finds the k digit maximum number possible
    vector <int> fun(vector <int>&nums, int k){
        if(k>nums.size()) return {};
        vector <int> res;
        stack <int> st;
        int rem = k, n = nums.size();
        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(nums[i]), rem--;
            else{
                int avail = n-i;
                while(!st.empty() and st.top()<nums[i] and rem<k and avail>rem) st.pop(), rem++;
                st.push(nums[i]), rem--;
            }
        }
        while(st.size()>k) st.pop();
        while(!st.empty()) res.push_back(st.top()), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
    void merge(vector <int>&a, vector <int>&b, vector <int>&res){
        int i = 0, j = 0, k = 0;
        // This is the only case which we need to take care of. Here, we loop until we find a number greater than another number
        // in other array. When we do that, we push the element in result array accordingly. Note that i am not using the pointer
        // i and j to loop, instead i have creater a temporary pointers which finds the position where elements are different.
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                int ti = i, tj = j;
                while(ti<a.size() and tj<b.size() and a[ti]==b[tj]) ti++, tj++;

                if(tj==b.size()) res.push_back(a[i]), i++;
                else
                if(ti<a.size() and a[ti]>b[tj]) res.push_back(a[i]), i++;
                else res.push_back(b[j]), j++;
            }
            else
            if(a[i]>b[j]) res.push_back(a[i]), i++;
            else res.push_back(b[j]), j++;
        }
        while(i<a.size()) res.push_back(a[i]), i++;
        while(j<b.size()) res.push_back(b[j]), j++;
    }
};