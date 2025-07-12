#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            int next = i + 1;
            while (next < n && temperatures[i] >= temperatures[next]) {
                if (answer[next] == 0) break; // No warmer day ahead
                next += answer[next];       // Skip ahead using jump table
            }
            if (next < n && temperatures[i] < temperatures[next]) {
                answer[i] = next - i; // Calculate days to the next warmer day
            }
        }

        return answer;
    }
};