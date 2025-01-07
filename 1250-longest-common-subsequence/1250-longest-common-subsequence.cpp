class Solution {
public:
    // string s,t;
    // int f( vector<vector<int>> &dp,int i,int j){
    //     if(i>=s.size() || j>=t.size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return 1+f(dp,i+1,j+1);
    //     }
    //     return dp[i][j]=max(f(dp,i+1,j),f(dp,i,j+1));
    // }
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),0));
        if(s[0]==t[0]){
            dp[0][0]=1;
        }
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                   if(i>0 && j>0) dp[i][j]=1+dp[i-1][j-1];
                   else{
                    dp[i][j]=1;
                   }
                }
                else{
                    if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
                    if(i>0 && j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
               }
            }
        }
        return dp[n-1][m-1];
        // return f(dp,0,0);
    }
};