class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum&1) return 0;
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) dp[i][j]=true;
                if(j<nums[i]){
                 if(i!=0) dp[i][j]=dp[i-1][j];
                }
                else if(j==nums[i]){
                    dp[i][j]=true;
                }
                else if(j>nums[i]){
                   if(i!=0) dp[i][j]=dp[i-1][j-nums[i]] || dp[i-1][j];
                }
            }
        }
        return dp[n-1][sum/2];
    }
};