class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        int n=nums.size();
        dp[0]=nums[0];
        if(n==1){
            return dp[0];
        }
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};