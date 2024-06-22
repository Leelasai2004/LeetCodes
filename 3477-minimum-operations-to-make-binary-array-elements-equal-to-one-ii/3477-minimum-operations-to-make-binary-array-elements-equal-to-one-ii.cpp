class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipped=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(flipped&1){
                if(nums[i]==1){
                    ans++;
                    flipped++;
                }
            }
            else{
                if(nums[i]==0){
                    ans++;
                    flipped++;
                }
            }
        }
        return ans;
    }
};