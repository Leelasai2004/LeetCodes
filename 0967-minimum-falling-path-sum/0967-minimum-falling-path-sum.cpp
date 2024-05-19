class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0) {
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    if(j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    if(j<n-1) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);

                    dp[i][j]+=matrix[i][j];
                }
                else{
                    dp[i][j]=matrix[i][j];
                }
            }
        }
        int minm=INT_MAX;
        for(int i=0;i<m;i++){
            minm=min(minm,dp[n-1][i]);
        }
        return minm;
    }
};