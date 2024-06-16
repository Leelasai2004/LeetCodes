
class Solution {
public:
    long long maximumTotalDamage(vector<int>& p) {
        map<long long,long long> mp;
        long long maxx=0;
        for(int i=0;i<p.size();i++){
            mp[p[i]]+=p[i];
        }
        map<long long,long long> dp;
        queue<pair<long long ,long long>> q;
        long long ans=0;
        for(auto m:mp){
            while(!q.empty() && q.front().first<m.first-2){
                maxx=max(maxx,q.front().second);
                q.pop();
            }
            dp[m.first]=m.second+maxx;
            ans=max(ans,dp[m.first]);
            q.push({m.first,ans});
        }
        return ans;
    }
};