class Solution {
public:
    int coinChange(vector<int>& coins, int need) {
        int dp[need+1];
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=need;i++){
            dp[i]=INT_MAX;
            for(auto c:coins){
                if(c>i) break;
                if(dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-c]);
                }

            }
        }
        if(dp[need]==INT_MAX){
            return -1;
        }
        return dp[need];
    }
};