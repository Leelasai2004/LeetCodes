class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        set<int> ind;
        vector<bool> ans;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]%2==nums[i]%2) ind.insert(i);
        }
        for(auto a: ind) cout<<a<<'\n';
        for(auto t:q){
            int a=t[0],b=t[1];
            auto y=ind.upper_bound(a);
            if(y==ind.end()) {ans.push_back(true);continue;}
            // cout<<*y<<'\n';
            if(*y<=b) ans.push_back(false);
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};