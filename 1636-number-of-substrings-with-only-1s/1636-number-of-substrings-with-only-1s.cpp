class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        map<int,int> mp;
        long long cnt=0;
        mp[0]=-1;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
                int last=mp[i+1-cnt];
                ans=(ans+(i-last))%(mod);
            }
            else{
                mp[i+1-cnt]=i;
            }
        }
        return (int)(ans%mod);
    }
};