#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Upper diagonals (excluding main diagonal) -> Min Heap
        for (int d = 1; d < n; d++) {
            int i = 0, j = d;
            priority_queue<int, vector<int>, greater<int>> pq;
            int dummyi = i, dummyj = j;

            while (i < n && j < n) {
                pq.push(grid[i][j]);
                i++; j++;
            }

            while (dummyi < n && dummyj < n) {
                grid[dummyi][dummyj] = pq.top();
                pq.pop();
                dummyi++; dummyj++;
            }
        }

        // Lower diagonals (including main diagonal) -> Max Heap
        for (int d = 0; d < n; d++) {
            int i = d, j = 0;
            priority_queue<int> pq; // max heap
            int dummyi = i, dummyj = j;

            while (i < n && j < n) {
                pq.push(grid[i][j]);
                i++; j++;
            }

            while (dummyi < n && dummyj < n) {
                grid[dummyi][dummyj] = pq.top();
                pq.pop();
                dummyi++; dummyj++;
            }
        }

        return grid;
    }
};