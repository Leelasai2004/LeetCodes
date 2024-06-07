class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int prev=-101;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=prev){
                nums[cnt]=nums[i];
                cnt++;
                prev=nums[i];
            }
        }
        return cnt;
    }
};