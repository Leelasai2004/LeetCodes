class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans=53.0;
        for(int i=0;i<nums.size();i++){
            double x=1.0*(nums[i]+nums[nums.size()-i-1])/2.0;
            ans=min(ans,x);
        }
        return ans;
    }
};