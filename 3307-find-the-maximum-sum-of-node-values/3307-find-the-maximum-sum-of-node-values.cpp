class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Initialize graph and visited array
        unordered_map<int, vector<int>> graph;
        int n = nums.size();
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
        // Declare dfs as a std::function for recursion
        function<pair<long long, long long>(int, vector<bool>&)> dfs = [&](int index, vector<bool>& visited) -> pair<long long, long long> {
            visited[index] = true;
            long long no_xor = nums[index];
            long long xor_val = nums[index] ^ k;
            long long max_sum = 0, num_xors = 0, min_diff = abs(no_xor - xor_val);
            
            if (xor_val > no_xor) {
                max_sum = xor_val;
                num_xors = 1;
            } else {
                max_sum = no_xor;
            }
            
            for (int neigh : graph[index]) {
                if (!visited[neigh]) {
                    auto result = dfs(neigh, visited);
                    long long child_no_xor = result.first;
                    long long child_xor = result.second;
                    min_diff = min(min_diff, abs(child_no_xor - child_xor));
                    
                    if (child_xor > child_no_xor) {
                        max_sum += child_xor;
                        num_xors++;
                    } else {
                        max_sum += child_no_xor;
                    }
                }
            }
            
            if (num_xors % 2 == 0) {
                return make_pair(max_sum, max_sum - min_diff);
            } else {
                return make_pair(max_sum - min_diff, max_sum);
            }
        };
        
        // Call DFS from the root (index 0)
        return dfs(0, visited).first;
    }
};