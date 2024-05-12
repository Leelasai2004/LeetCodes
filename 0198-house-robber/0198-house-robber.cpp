class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int taken,nottaken;
        nottaken=nums[0];
        if(n==1){
            return nottaken;
        }
        taken=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int newt=max(taken,nottaken+nums[i]);
            int newn=max(taken,nottaken);
            taken=newt;
            nottaken=newn;
        }
        return max(taken,nottaken);
    }
};