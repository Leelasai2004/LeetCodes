class Solution {
public:
    const long long mod=(int)1e9+7;
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        map<int,int> mp;
        for(auto r:requirements){
            mp[r[0]+1]=r[1];
        }
        vector<vector<int>> dp(n+1,vector<int>(401,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            long long sum=0;
            for(int j=0;j<=400;j++){
                sum+=dp[i-1][j];
                if(j>=i){
                    sum-=dp[i-1][j-i];
                }
                dp[i][j]=sum%mod;
            }
            if(mp.find(i)!=mp.end()){
                for(int j=0;j<=400;j++){
                    if(j!=mp[i]){
                        dp[i][j]=0;
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<=400;i++){
            ans=(ans+dp[n][i])%mod;
        }
        return (int)ans;
    }
};