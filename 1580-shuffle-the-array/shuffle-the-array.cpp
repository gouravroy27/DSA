class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];         
            ans[2 * i + 1] = nums[i + n]; 
        }
        
        return ans;
    }
};