class Solution {
public:
    long long maximumPoints(vector<int>& v, int x) {
        sort(v.begin(),v.end());
        if(x<v[0]){
            return 0;
        }
        long long ans=accumulate(v.begin(),v.end(),0LL)+x;
        ans-=v[0];
        ans/=v[0];
        return ans;
    }
};