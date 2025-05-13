const int INF = 1e9;
class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        
     
        if(dp[i][j]!=-1000000)return dp[i][j];
        
        if(i==0)return mat[i][j];
        int up=INF,ld=INF,rd=INF;
          up = mat[i][j] + fun(i - 1, j, mat, dp);
         if(j>0)
          ld = mat[i][j] + fun(i - 1, j - 1,  mat, dp);
         if(j<mat[0].size()-1)
          rd = mat[i][j] + fun(i - 1, j + 1, mat, dp);
         return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[m-1].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1000000));
        for(int i=0;i<n;i++){
           mini=min(mini,fun(m-1,i,mat,dp));
        }
        return mini;
    }
};