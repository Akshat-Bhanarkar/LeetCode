int q[50000], front=0, back=0;
class Solution {
public:
    int n, m, strength;
    bool doable(vector<int>& tasks, vector<int>& workers, int k, int pills){
        int t_idx=0;
        front=back=0;// reset for the pointers for q
        for (int i=m-k; i<m; i++){
            int W=workers[i];
            for(; t_idx<k && tasks[t_idx]<=W+strength; t_idx++)
                q[back++]=tasks[t_idx];
            
            if (front==back) return 0;
            if (q[front]<=W) front++;//no need for pill for easiest task
            else{
                if (pills==0) return 0;
                pills--;
                back--; //take a pill for hardest task
            }
        }
        return 1;

    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n=tasks.size(), m=workers.size();
        this->strength=strength;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l=0, r=min(n, m);

        while (l<r) {
            int mid=(l+r+1)/2;
            if (doable(tasks, workers, mid, pills))
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
};