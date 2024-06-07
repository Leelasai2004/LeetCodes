class Solution {
public:
    bool check(vector<int>& nums) {
        bool f=false,g=false;
        int prev=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(f){
                    return false;
                }
                if(!f){
                    f=true;
                }
        
                // prev=nums[i];
            }
            
        }
        if(f){
            return prev>=nums.back();
        }
        return true;
    }
};