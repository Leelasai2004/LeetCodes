class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return true; 
        if (dp[i] != -1) return dp[i]; 

        bool left = false;
        if (i >= 1 && nums[i] == nums[i - 1]) {
            left = solve(i - 2, nums, dp);
        }

        bool right = false;
        if (i >= 2 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
            right = solve(i - 3, nums, dp);
        }

        bool center = false;
        if (i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
            center = solve(i - 3, nums, dp);
        }

        return dp[i] = left || right || center;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); 
        return solve(n - 1, nums, dp);
    }
};
