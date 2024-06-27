class Solution {
public:
    int findCircleNum(vector<vector<int>>& C) {
        int n=C.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            ans++;
            dfs(i,vis,C);
        }
        return ans;
    }
    void dfs(int i,vector<int>&vis,vector<vector<int>>& C){
        vis[i]=1;
        int n=C.size();
        for(int j=0;j<n;j++){
            if(C[i][j] && !vis[j]){
                dfs(j,vis,C);
            }
        }
    }
};