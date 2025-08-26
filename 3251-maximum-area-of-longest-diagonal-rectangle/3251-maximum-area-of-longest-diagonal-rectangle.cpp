class Solution {
public:
    // Function to calculate the area of the rectangle with the longest diagonal
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        // Get the number of rectangles
        int n = dimensions.size();

        // Initialize variables to keep track of maximum area and diagonal
        int maxArea = 0, maxDiag = 0;

        // Iterate through each rectangle
        for (int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int currDiag = l * l + w * w;

            if (currDiag > maxDiag || (currDiag == maxDiag && l * w > maxArea)) {
                maxDiag = currDiag;
                maxArea = l * w;
            }
        }
        return maxArea;
    }
};