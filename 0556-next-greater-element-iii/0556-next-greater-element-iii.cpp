class Solution {
public:
    int nextGreaterElement(int n) {
        // Step 1: Convert the Number to Digits
        vector<int> x;
        int temp = n;
        while (temp) {
            x.push_back(temp % 10); // Extract the last digit
            temp = temp / 10; // Remove the last digit
        }
        reverse(x.begin(), x.end()); // Reverse to get digits in correct order
        
        // Step 2: Identify the First Decreasing Digit
        int i = x.size() - 1;
        while (i > 0 && x[i - 1] >= x[i])
            i--;
        
        // If no such digit is found, return -1
        if (i == 0)
            return -1;
        
        // Step 3: Find the Smallest Greater Digit on the Right
        int j = x.size() - 1;
        while (x[j] <= x[i - 1])
            j--;
        
        // Step 4: Swap and Sort
        swap(x[i - 1], x[j]); // Swap x[i - 1] with the smallest greater digit
        reverse(x.begin() + i, x.end()); // Sort the digits to the right in ascending order
        
        // Step 5: Handle Overflow
        long long res = 0;
        for (int k = 0; k < x.size(); k++) {
            res = res * 10 + x[k]; // Construct the next greater number
            // Check for integer overflow
            if (res > INT_MAX)
                return -1;
        }
        
        return res;
    }
};