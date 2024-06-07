class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        int n=nums.size();
        k%=n;
        for(int i=0;i<n;i++){
            res[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=res[i];
        }
    }
};