class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long> dp(n+1,0);
        for(int i=1;i<=n;i++){
            long long now=nums[i-1];
            dp[i]=max(dp[i-1]+nums[i-1],(i>=2?dp[i-2]+nums[i-2]-nums[i-1]:LLONG_MIN));
        }
        return dp[n];
    }
};