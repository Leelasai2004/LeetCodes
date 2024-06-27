class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto v:edges){
            mp[v[0]]++,mp[v[1]]++;
        }
        int n=mp.size();
        for(auto p:mp){
            if(p.second==n-1){
                return p.first;
            }
        }
        return -1;

    }
};