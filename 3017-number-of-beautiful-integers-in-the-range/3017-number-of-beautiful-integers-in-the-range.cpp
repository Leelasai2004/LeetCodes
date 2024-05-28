class Solution {
    #define ll long long
    int k, mod = 1e9+7;
    ll dp[11][2][11][11][2][21];
    int f(int i, bool leading, int odd, int even, bool tight, ll sum, string &s) {
        if(i>=s.size()) {
            if(odd==even && sum%k==0) return 1;
            return 0;
        }
        if(dp[i][leading][odd][even][tight][sum]!=-1) {
            return dp[i][leading][odd][even][tight][sum];
        }

        int high = tight ? s[i]-'0' : 9;
        ll ans = 0;
        for(int low = 0 ; low<=high ; ++low) {
            int nodd = odd, neven = even;
            if(low&1) nodd++;
            else neven++;
            bool nleading = leading&(low==0);
            bool ntight = tight&(low==high);
            ll nsum = (sum*10+low)%k;
            if(leading) {
                ans = (ans + f(i+1,nleading,low?nodd:0,low?neven:0,ntight,nsum,s))%mod;
            }else ans = (ans + f(i+1,nleading,nodd,neven,ntight,nsum,s))%mod;
        }

        return dp[i][leading][odd][even][tight][sum] = ans;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;
        ll ans1 = 0, ans2 = 0;
        if(low > 0) {
            string s1 = to_string(low-1);
            memset(dp,-1,sizeof(dp));
            ans1 = f(0,1,0,0,1,0,s1);
        }
        
        string s2 = to_string(high);
        memset(dp,-1,sizeof(dp));
        ans2 = f(0,1,0,0,1,0,s2);
        return ans2-ans1;
    }
};