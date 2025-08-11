class Solution {
public:
    bool isprime(int x){
        if (x <= 1) return false;
        for(int i = 2; i*i <= x; i++){
            if (x%i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (unsigned int i = left; i <= right; i++){
            int setbits = __builtin_popcount(i);
            if (isprime(setbits)) count++;
        }
        return count;
    }
};