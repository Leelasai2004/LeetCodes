class Solution {
public:


    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans++;
                if(i>nums.size()-3){
                    return -1;
                }
                nums[i]=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
            }
        }
        return (count(nums.begin(),nums.end(),1)==nums.size())?ans:-1;
    }
};