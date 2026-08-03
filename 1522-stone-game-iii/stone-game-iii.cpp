class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = -1e9; 
            int current_sum = 0;

            for (int k = 0; k < 3 && i + k < n; ++k) {
                current_sum += stoneValue[i + k];
                dp[i] = max(dp[i], current_sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};