class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        
        for (int i = 0; i < nums.size(); ++i) {
            // Flip the i-th character of the i-th string
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};