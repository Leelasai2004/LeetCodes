class Solution {
public:
    int dy[3]={-1,0,1};
    int helper(vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int i ,int j1,int j2){
        int m=grid[0].size(),n=grid.size();
        if(i>=n || j1<0 ||j2<0 || j1>=m || j2>=m){
            return -1e8;
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==n-1){
            if(j1==j2) return dp[i][j1][j2]=grid[i][j1];
            else{
                return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
            }
        }

        int maxi=0;
        for(auto d1:dy){
            for(auto d2:dy){
                if(j1==j2) maxi=max(maxi,grid[i][j1]+helper(grid,dp,i+1,j1+d1,j2+d2));
                else {
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+helper(grid,dp,i+1,j1+d1,j2+d2));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
      return helper(grid,dp,0,0,m-1);
    }
};