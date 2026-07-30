class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long max_w = *max_element(workerTimes.begin(), workerTimes.end());
        long long high = max_w * (long long)mountainHeight * (mountainHeight + 1) / 2;
        
        long long ans = high;

        auto check = [&](long long T) {
            long long total_reduced = 0;
            for (int w : workerTimes) {
                long long max_x = (sqrt(1.0 + 8.0 * T / w) - 1.0) / 2.0;
                total_reduced += max_x;
                if (total_reduced >= mountainHeight) {
                    return true;
                }
            }
            return total_reduced >= mountainHeight;
        };

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid time
            } else {
                low = mid + 1; // Increase time
            }
        }

        return ans;
    }
};