class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long n=nums.size();
        vector<vector<int>> v(13);
        for(auto x:nums){
            string s=to_string(x);
            for(int i=0;i<s.size();i++){
                v[i].push_back(s[i]-'0');
            }
        }
        // for(int i=0;i<13;i++){
        //     // for(auto x:v[i]) cout<<x<<" ";
        //     // cout<<'\n';
        //     sort(v[i].begin(),v[i].end());
        // }
        long long prev=0,ans=0;
        map<int,long long> count;
        for(int i=0;i<13;i++){
           count.clear();
            for(auto x:v[i]) count[x]++;
            int prev=0;
            for(int j=0;j<10;j++){
                ans+=count[j]*(n-prev-count[j])+count[j]*prev;
                prev=count[j];
            }
        }
        return ans/2;
    }
};