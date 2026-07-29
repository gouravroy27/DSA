class DSU {
public:
    vector<int> parent;
    int components;

    DSU(int n) : components(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU mandatory_dsu(n);
        int min_mandatory_strength = 2e9;
        bool has_mandatory = false;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
            if (must == 1) {
                has_mandatory = true;
                min_mandatory_strength = min(min_mandatory_strength, s);
                if (!mandatory_dsu.unite(u, v)) {
                    return -1;
                }
            }
        }

        DSU full_dsu(n);
        int max_s = 0;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], s = edge[2];
            full_dsu.unite(u, v);
            max_s = max(max_s, s);
        }
        if (full_dsu.components > 1) {
            return -1; 
        }

        int low = 1;
        int high = has_mandatory ? min_mandatory_strength : max_s * 2;
        int ans = -1;

        auto check = [&](int T) {
            if (has_mandatory && min_mandatory_strength < T) {
                return false;
            }

            DSU dsu(n);

            for (const auto& edge : edges) {
                if (edge[3] == 1) {
                    dsu.unite(edge[0], edge[1]);
                }
            }

            for (const auto& edge : edges) {
                if (edge[3] == 0 && edge[2] >= T) {
                    dsu.unite(edge[0], edge[1]);
                }
            }

            int upgrades_used = 0;
            for (const auto& edge : edges) {
                if (edge[3] == 0 && edge[2] < T && edge[2] * 2 >= T) {
                    if (dsu.find(edge[0]) != dsu.find(edge[1])) {
                        if (upgrades_used < k) {
                            dsu.unite(edge[0], edge[1]);
                            upgrades_used++;
                        }
                    }
                }
            }

            return dsu.components == 1;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};