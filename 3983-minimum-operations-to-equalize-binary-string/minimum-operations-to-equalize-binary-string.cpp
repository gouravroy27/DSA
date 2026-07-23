class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) {
            if (c == '0') initial_zeros++;
        }
        
        if (initial_zeros == 0) return 0;
        
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }
        
        queue<pair<int, int>> q; 
        
        unvisited[initial_zeros % 2].erase(initial_zeros);
        q.push({initial_zeros, 0});
        
        while (!q.empty()) {
            auto [z, steps] = q.front();
            q.pop();
            
            int min_x = max(0, k - (n - z));
            int max_x = min(z, k);
            
            int L = z + k - 2 * max_x;
            int R = z + k - 2 * min_x;
            
            int target_parity = (z + k) % 2;
            auto& s_set = unvisited[target_parity];
            
            auto it = s_set.lower_bound(L);
            vector<int> to_remove;
            
            while (it != s_set.end() && *it <= R) {
                int next_z = *it;
                if (next_z == 0) {
                    return steps + 1;
                }
                q.push({next_z, steps + 1});
                to_remove.push_back(next_z);
                it++;
            }
            
            for (int val : to_remove) {
                s_set.erase(val);
            }
        }
        
        return -1;
    }
};