class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
    int n=v.size();
    map<int,int> mp;
    int sum=0;
    mp[sum]++;
    int ans=0;
    for(int i=0;i<n;i++){
// dbg(sum,mp[sum]);        
        sum+=v[i];
        ans+=mp[sum-k];
        mp[sum]++;
    }
    return ans;
    }
};