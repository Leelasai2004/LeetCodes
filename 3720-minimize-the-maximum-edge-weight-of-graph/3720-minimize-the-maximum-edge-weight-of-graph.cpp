class Solution {
    void dfs(int node, vector<vector<pair<int,int>>>& graph, vector<bool>& vis,int mid) {
        vis[node] = true;
        for (auto i : graph[node]) {
            if (i.second<=mid && !vis[i.first]) {
                dfs(i.first, graph, vis,mid);
            }
        }
    }

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < edges.size(); i++) {
            lo = min(edges[i][2], lo);
            hi = max(edges[i][2], hi);
        }
        int ans = -1;
        vector<vector<pair<int,int>>> graph(n);
            vector<int> out(n, 0);
            for (auto i : edges) {
                // if (i[2] <= mid) {
                    // graph[i[0]].push_back(i[1]);
                    graph[i[1]].push_back({i[0],i[2]});
                    out[i[0]]++;
                    out[i[1]]++;
                // }
            }
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<bool> vis(n, false);
            dfs(0, graph, vis, mid);
            bool f = true;
            for (auto v : vis) {
                if (!v) {
                    f = false;
                    break;
                }
            }

            if (f) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};