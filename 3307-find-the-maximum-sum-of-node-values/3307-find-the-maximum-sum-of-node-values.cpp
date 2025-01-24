#define ll long long int
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll n = nums.size();
        vector<vector<ll>>adj(n);
        for(auto i:edges){
            ll a = i[0],b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto f = [&](ll node,ll par,auto &&self)->pair<ll,ll>{
            ll a = nums[node],b = nums[node]^k;
            ll sum = 0,y = 0;
            ll mini= abs(a-b);
            if(a>b){
                sum+=a;
            }
            else{
                sum+=b;
                y++;
            }
            for(auto i:adj[node]){
                if(i!=par){
                    pair<ll,ll> x = self(i,node,self);
                    mini=min(mini,abs(x.first-x.second));
                    if(x.first >= x.second){
                        sum+=x.first;
                    }
                    else{
                        sum+=x.second;
                        y++;
                    }
                }
            }
            if(y&1){
                a=sum-mini;
                b= sum;
            }
            else{
                a = sum;
                b = sum-mini;
            }
            return {a,b};
        };
        pair<ll,ll> x = f(0,-1,f);
        return x.first;
    }
};
