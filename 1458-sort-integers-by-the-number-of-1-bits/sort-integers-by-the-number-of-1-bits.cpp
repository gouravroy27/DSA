class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // Primary condition: sort by bit count
            if (countA != countB) {
                return countA < countB;
            }
            
            // Secondary condition: tie-breaker by value
            return a < b;
        });
        
        return arr;
    }
};