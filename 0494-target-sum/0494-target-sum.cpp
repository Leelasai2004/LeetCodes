
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<target || (sum+target)&1){
            return 0;
        }
        return countSubarrayofSum(nums,(sum+target)>>1);
    }
    int countSubarrayofSum(vector<int>& nums,int target){
        int n=nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                // cout<<"#"<<i<<"#"<<j<<dp[i][j]<<'\n';
            }
        }
        return dp[n][target];
    }
};