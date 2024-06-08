// #define int long long
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));

        for (int i = 1; i <= n; ++i) {

            for (int j = 0; j <= k; ++j) {

                for (int l = 1; l < i; l++) {

                    if (nums[i - 1] != nums[l - 1]) {
                        if (j > 0)
                            dp[i][j] = max(dp[i][j], dp[l][j - 1] + 1);
                    } else {

                        dp[i][j] = max(dp[l][j] + 1, dp[i][j]);
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; ++j) {
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};