class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
        vector<int>v(26,0);

        for(char &ch:tasks) v[ch-'A']++;

        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(v[i]>0) pq.push(v[i]);
        }

        while(!pq.empty()){
            vector<int>temp;

            // Doing tasks
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &i:temp){
                if(i>0) pq.push(i);
            }

            // Last set of tasks
            if(pq.empty()) ans+=temp.size();
            // Did (n+1) tasks
            else ans+=(n+1);
        }
        return ans;
    }
};