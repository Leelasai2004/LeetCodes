class Solution {
public:
    int dy[3]={-1,0,1};
    bool in_bound(int j,int m){
        if(j>=0 && j<m){
            return true;
        }
        return false;
    }
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
    //   return helper(grid,dp,0,0,m-1);
        dp[0][0][m-1]=grid[0][0]+grid[0][m-1];
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1;
                    for(int d1=0;d1<3;d1++){
                        for(int d2=0;d2<3;d2++){
                            if(in_bound(j1+dy[d1],m) && in_bound(j2+dy[d2],m)){
                                if(j1==j2) maxi=max(maxi,dp[i-1][j1+dy[d1]][j2+dy[d2]]);
                                else{
                                    maxi=max(maxi,dp[i-1][j1+dy[d1]][j2+dy[d2]]);
                                }
                            }
                        }
                    }
                   if(maxi!=-1 && j1!=j2) dp[i][j1][j2]=maxi+grid[i][j1]+grid[i][j2];
                   if(maxi!=-1 && j1==j2) dp[i][j1][j2]=maxi+grid[i][j1];
                    if(ans<dp[i][j1][j2]) ans=dp[i][j1][j2];
                }
            }
        } 
        
        return ans;
    }
};