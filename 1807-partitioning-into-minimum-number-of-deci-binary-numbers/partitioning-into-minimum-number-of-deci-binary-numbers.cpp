class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        
        for (char c : n) {
            max_digit = max(max_digit, c - '0');            
            if (max_digit == 9) return 9;
        }
        
        return max_digit;
    }
};