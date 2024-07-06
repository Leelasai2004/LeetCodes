
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       long long ans=0;
       for(auto ele : nums)
       {
            unordered_map<int,int> nmp;
            nmp[ele]++;
            for(auto val : mp)
              nmp[val.first&ele]+=val.second;
            ans+=nmp[k];
            mp=nmp;
       }
       return ans;
    }
};
