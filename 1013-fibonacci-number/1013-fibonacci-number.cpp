class Solution {
public:
    int help(int i,vector<int>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=help(i-1,dp)+help(i-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+2,-1);
        dp[0]=0;
        dp[1]=1;
        return help(n,dp);
    }
};