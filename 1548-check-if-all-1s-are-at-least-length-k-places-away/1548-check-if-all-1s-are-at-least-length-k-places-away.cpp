class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(cnt1==0){
                    cnt=0;
                    cnt1++;
                    continue;
                }
                cnt1++;
                if(cnt<k) return false;
                cnt=0;
            }else{
                cnt++;
            }
        }
        return true;
    }
};