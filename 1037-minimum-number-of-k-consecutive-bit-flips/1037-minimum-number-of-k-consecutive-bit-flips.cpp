class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int currflips=0,total=0;
        int n=nums.size();
        vector<int> flipped(n,0);
        for(int i=0;i<n;i++){
            if(i>=k){
                if(flipped[i-k]){
                    currflips--;
                }
            }
            if(nums[i]==0 && currflips&1){
                continue;
            }
            if(nums[i]==1 && currflips%2==0){
                continue;
            }
            if(i+k>n){
                return -1;
            }
            currflips++;
            flipped[i]=1;
            total++;
        }
        return total;
    }
};