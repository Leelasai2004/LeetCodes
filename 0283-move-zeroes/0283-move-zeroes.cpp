class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int r=0;
       int cnt=0;
       while(r<nums.size()){
            if(nums[r]!=0){
                nums[cnt]=nums[r];
             if(cnt!=r)   nums[r]=0;
                cnt++;
            }
            r++;
       }
    }
};