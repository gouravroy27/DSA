class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> operations;
        int targetIndex = 0;
        
        for(int num = 1; num <= n; ++num) {
            if(targetIndex == target.size()) {
                break;
            }            
            operations.push_back("Push");            
            if(num == target[targetIndex]) {
                targetIndex++;
            } 
            else{
                operations.push_back("Pop");
            }
        }
        
        return operations;
    }
};