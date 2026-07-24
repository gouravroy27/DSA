class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled = s + s;
        
        int diff0 = 0, diff1 = 0;
        int min_flips = INT_MAX;
        
        for (int i = 0; i < 2 * n; ++i) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            
            if (doubled[i] != expected0) diff0++;
            if (doubled[i] != expected1) diff1++;            
            if (i >= n) {
                char old0 = ((i - n) % 2 == 0) ? '0' : '1';
                char old1 = ((i - n) % 2 == 0) ? '1' : '0';
                
                if (doubled[i - n] != old0) diff0--;
                if (doubled[i - n] != old1) diff1--;
            }            
            if (i >= n - 1) {
                min_flips = min({min_flips, diff0, diff1});
            }
        }
        
        return min_flips;
    }
};