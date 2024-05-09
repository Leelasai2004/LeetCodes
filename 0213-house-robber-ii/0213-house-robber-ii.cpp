class Solution {
public:
    int robhelper(vector<int>& nums,int start,int end) {
       int taken,not_taken;
       not_taken=nums[start];
       if(nums.size()==1){
        return not_taken;
       }
       taken=max(nums[start],nums[start+1]);
       for(int i=start+2;i<=end;i++){
        int nwnot=taken;
        int nwtaken=max(taken,not_taken+nums[i]);
        taken=nwtaken;
        not_taken=nwnot;
       }
        return max(taken,not_taken);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        return max(robhelper(nums,0,n-2),robhelper(nums,1,n-1));
    }
};