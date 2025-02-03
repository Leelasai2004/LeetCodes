class Solution {
public:
    vector<vector<int>> ans;
    map<string, int> mp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        string s = "";
        solve(candidates, 0, 0, target, v, s);
        return ans;
    }

    void solve(vector<int>& nums, int ind, int sum, int target, vector<int>& v, string& s) {
        if (ind >= nums.size()) {
            if (sum == target && mp.find(s) == mp.end()) {
                mp[s]++;
                ans.push_back(v);
            }
            return;
        }

        if (sum + nums[ind] <= target) {
            v.push_back(nums[ind]);
            string temp = s + to_string(nums[ind]);
            solve(nums, ind + 1, sum + nums[ind], target, v, temp);
            v.pop_back();
        }

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) ind++;
        solve(nums, ind + 1, sum, target, v, s);
    }
};