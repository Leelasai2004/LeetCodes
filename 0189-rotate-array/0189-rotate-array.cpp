class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        int n=nums.size();
        for(int i=0;i<n;i++){
            res[i]=nums[((n+i-k)%n+n)%n];
        }
        for(int i=0;i<n;i++){
            nums[i]=res[i];
        }
    }
};