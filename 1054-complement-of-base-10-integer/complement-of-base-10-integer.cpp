class Solution {
public:
    int bitwiseComplement(int n) {
        // Special base case for 0 ("0" in binary becomes "1")
        if (n == 0) return 1;
        
        // Find the bit mask of all 1s of the same length as n
        unsigned int mask = ~0;
        
        while (n & mask) {
            mask <<= 1;
        }
        
        // mask now has 0s where n has bits, and 1s above n's MSB.
        // ~mask creates a bitmask of all 1s corresponding to n's length.
        return n ^ (~mask);
    }
};