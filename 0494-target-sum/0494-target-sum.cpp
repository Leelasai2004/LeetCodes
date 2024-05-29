void __print(int x) { cout << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x){cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template <typename T>
void __print(const T &x){int f = 0;cerr << '{';for (auto &i : x)cerr << (f++ ? "," : ""), __print(i);cout << "}";}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{__print(t);if (sizeof...(v))cerr << ", ";_print(v...);}

#define dbg(x...)               \
  cout << "[" << #x << "] = ["; \
  _print(x)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> dp1;
        dp1[0]=1;
        for(int i=0;i<nums.size();i++){
            map<int,int> dp2;
            for(auto prev:dp1){
                int now=prev.first+nums[i];
                dp2[now]=dp2[now]+prev.second;
                now=prev.first-nums[i];
                dp2[now]=dp2[now]+prev.second;
            }
            
            cout<<'\n';
            dp1=dp2;
            // dbg(dp1);
        }
        int ans=dp1[target];
        return ans;
        
    }
};