class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        
        for (int length = 2; length <= 9; ++length) {
            
            for (int startDigit = 1; startDigit <= 10 - length; ++startDigit) {
                int num = startDigit;
                int nextDigit = startDigit;
                
                for (int i = 1; i < length; ++i) {
                    nextDigit++;
                    num = num * 10 + nextDigit;
                }
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};