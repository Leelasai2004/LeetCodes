class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        int n=power.size();
        vector<long long> dp(n,0);
        int i=0,j=0;
         long long mx=0;
         int prev=0;
        for(;i<n;i++){
            while(power[j]<power[i]-2){
                mx=max(mx,dp[j]);
                j++;
            }
            long long cnt=1;
            if(i) prev=i-1;
            while(i<n-1 && power[i]==power[i+1]){
                cnt++;
                i++;
            }
            // cout<<power[i]<<" "<<cnt<<'\n';
            dp[i]=mx+1LL*cnt*power[i];
            if(i && prev) dp[i]=max(dp[prev],dp[i]);
        }
        return dp[n-1];
    }
};