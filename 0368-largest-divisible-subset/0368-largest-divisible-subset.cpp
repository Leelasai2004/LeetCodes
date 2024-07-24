class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mxi=0,lst=0;
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    hash[i]=j;
                }
            }
            if(dp[i]>mxi){
                lst=i;
                mxi=dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[lst]);
        while(lst!=hash[lst]){
            lst=hash[lst];
            ans.push_back(nums[lst]);
        }
        return ans;

    
    }
};