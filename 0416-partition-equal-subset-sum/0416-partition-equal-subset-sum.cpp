class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int n=nums.size();
        // bitset<10001> bits(1);
        // for (auto &x: nums) bits |= bits << x;
        // return bits[sum >> 1];
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=0;j--){
                if(j>=nums[i]) dp[j]=dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum/2];
    }
};
