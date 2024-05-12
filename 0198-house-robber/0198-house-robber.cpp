class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int take,nottake;
        take=nums[0];
        if(n==1){
            return take;
        }
        nottake=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int newt=max(take,nottake);
            int newn=max(take+nums[i],nottake);
            take=newt;
            nottake=newn;
        }
        return max(take,nottake);
    }
};