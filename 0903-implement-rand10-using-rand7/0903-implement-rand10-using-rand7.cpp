class Solution {
public:
    int n, m;
    int rand10() {
        // initialising the values
		n = rand7(), m = 7;
        // making sure n is in the right 1-5 range and, if we can, we settle m too
		while (n > 5) {
            m = n - 5;
            n = rand7();
        }
        // if m was not settled, we do it here
		while (m == 7) m = rand7();
        return (m % 2 ? 5 : 0) + n;
    }
};