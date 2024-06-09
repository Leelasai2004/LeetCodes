class Solution {
public:
    long long mod=(int)1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long> v(n,1);
        vector<long long> ans(n);
        while(k--){
            partial_sum(v.begin(),v.end(),ans.begin());
            for(int i=0;i<n;i++){
                if(ans[i]>=mod){
                    ans[i]%=mod;
                }
                v[i]=ans[i];
            }
        }
        return v[n-1]%mod;

    }
};