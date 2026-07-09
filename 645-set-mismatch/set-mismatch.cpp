class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1;
        int missing = -1;
        for (int num : nums){
            int idx = std :: abs(num) -1;
            if(nums[idx]<0) {
                duplicate = std::abs(num);
            } else {
                nums[idx] *= -1;
            }
        }
        for(int i = 0; i< nums.size(); ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
            } else {
                nums[i] *= -1;
            }
        } 
        return {duplicate, missing};
    }
};

