class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(dp[i-1][j]!=INT_MAX) dp[i][j]=dp[i-1][j]+triangle[i][j];
                if(j!=0 && dp[i-1][j-1]!=INT_MAX) dp[i][j]=min(dp[i][j],triangle[i][j]+dp[i-1][j-1]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};