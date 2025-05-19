class Solution {
public:
    bool isChange(vector<bool> &rotate, vector<int> &rotatedValue, int num) {
        int x = num;
        int NewNum = 0;
        bool changed = false;
        int place = 1;

        while (num > 0) {
            int digit = num % 10;
            num /= 10;

            if (!rotate[digit]) return false;//checking digits if it a single digits is invalid mean whole nuumber is invalid after rotation
            
            int rotatedDigit = rotatedValue[digit];
            // we check if digit does't change after rotation
            if (rotatedDigit != digit) changed = true;

            
            NewNum = rotatedDigit * place + NewNum;
            place *= 10;
        }
        return changed;
    }

    int rotatedDigits(int n) {
        vector<bool> rotate = {true, true, true, false, false, true, true, false, true, true};
        vector<int> rotatedValue = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isChange(rotate, rotatedValue, i)) {
                cnt++;
            }
        }
        return cnt;
    }
};