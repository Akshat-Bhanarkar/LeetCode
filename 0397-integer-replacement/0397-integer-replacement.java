class Solution {
    // please upvote :)
    public int integerReplacement(int n) {
        long num = n;  // use long to avoid overflow on n+1
        int cnt = 0;
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                if (num == 3 || num % 4 == 1) {
                    num--;
                } else {
                    num++;
                }
            }
            cnt++;
        }
        return cnt;
    }
}