class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxGold=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxGold=max(maxGold,dfs(grid,i,j,n,m));
            }
        }
        return maxGold;
    }
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return 0;
        }
        int curr=grid[i][j];
        int gold=0;
        grid[i][j]=0;
        for(int x=0;x<4;x++){
            gold=max(gold,curr+dfs(grid,i+dx[x],j+dy[x],n,m));
        }
        grid[i][j]=curr;
        return gold;
    }
};