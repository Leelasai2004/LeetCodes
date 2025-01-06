class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(302,vector<int>(302,0));
        // dp[prev][diff]-> max length of subsequence with last element =prev, difference >= diff;
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int prev=1;prev<=300;prev++){
                int diff=abs(num-prev);
                dp[num][diff]=max(dp[num][diff],dp[prev][diff]+1);
            }
            // we need to calculate dp[i][j]=max(dp[i][j],dp[i][j+1],dp[i][j+2])....
            // to reduce time complexity on computing next state..
            for (int diff = 300; diff >= 0; --diff){
                dp[num][diff] = max(dp[num][diff], dp[num][diff + 1]);
            }
        }
        int ans=2;
        for(int num=0;num<=300;num++){
            for(int diff=0;diff<=300;diff++){
                ans=max(ans,dp[num][diff]);
            }
        }
        return ans;
    }
};