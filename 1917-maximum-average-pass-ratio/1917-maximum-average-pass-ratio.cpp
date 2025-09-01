class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto [g, p] = pq.top(); pq.pop();
            int pass = p.first + 1;
            int total = p.second + 1;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            sum += (double)p.first / p.second;
        }

        return sum / classes.size();
    }
};