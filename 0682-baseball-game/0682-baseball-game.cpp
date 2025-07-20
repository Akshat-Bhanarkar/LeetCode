class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;

        for (string s : op) {
            if (s == "C") {
                st.pop();
            } else if (s == "D") {
                st.push(2 * st.top());
            } else if (s == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);        // push back top1
                st.push(top1 + top2); // push sum
            } else {
                st.push(stoi(s)); // Convert string to integer
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};