class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n,vector<int>(k+1,1));
        vector<int> mx(k+1,0);
        for(int i=0;i<n;i++){
            for(int j=k;j>=0;j--){
                if(mp.find(nums[i])!=mp.end()){
                    dp[i][j]=max(dp[i][j],dp[mp[nums[i]]][j]+1);
                }
                if(j>0) dp[i][j]=max(dp[i][j],1+mx[j-1]);
                mx[j]=max(mx[j],dp[i][j]);
            }
            mp[nums[i]]=i;
            res=max(res,dp[i][k]);
        }
        return res;
    }
};