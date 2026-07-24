class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int MOD = 1e9 + 7;
        int len = 0; // Number of bits for the current integer
        
        for (int i = 1; i <= n; ++i) {
            // If i is a power of 2, its bit length increases by 1
            if ((i & (i - 1)) == 0) {
                len++;
            }
            
            // Shift existing result to the left by len bits and add current number i
            ans = ((ans << len) | i) % MOD;
        }
        
        return ans;
    }
};