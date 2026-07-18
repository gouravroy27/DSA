class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bool isPrime[21] = {false};
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
        isPrime[11] = isPrime[13] = isPrime[17] = isPrime[19] = true;
        
        int primeSetBitOps = 0;
        
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i);
            
            if (isPrime[setBits]) {
                primeSetBitOps++;
            }
        }
        
        return primeSetBitOps;
    }
};