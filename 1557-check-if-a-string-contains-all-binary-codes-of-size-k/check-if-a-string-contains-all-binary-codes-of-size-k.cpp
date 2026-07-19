class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int total_codes = 1 << k; 
        
        if (n - k + 1 < total_codes) {
            return false;
        }
        
        vector<bool> seen(total_codes, false);
        int unique_count = 0;
        
        int current_value = 0;
        int mask = total_codes - 1; 
        
        for (int i = 0; i < n; i++) {
            current_value = ((current_value << 1) | (s[i] - '0')) & mask;
            
            if (i >= k - 1) {
                if (!seen[current_value]) {
                    seen[current_value] = true;
                    unique_count++;
                    
                    if (unique_count == total_codes) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};