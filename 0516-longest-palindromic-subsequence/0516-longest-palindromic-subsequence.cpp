class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        int n=t.size();
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    dp[i][j]=1;
                    if(i && j) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                else{
                    if(i) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][n-1];
    }
};