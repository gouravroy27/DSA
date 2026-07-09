class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    
        std::vector<int> count(101, 0);
        for (int num : nums) {
            count[num]++;
        }
        int runningSum = 0;
        for (int i = 0; i <= 100; ++i) {
            int currentFreq = count[i];
            count[i] = runningSum;
            runningSum += currentFreq;
        }
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = count[nums[i]];
        }
        
        return result;
    }
};