class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0,r=0;
        int ans=0;
        while(l<s.size() && r<t.size()){
            if(s[l]==t[r]){
                l++;
                r++;
                ans++;
            }
            else{
                l++;
            }
        }
        // cout<<ans<<'\n';
        return (int)t.size()-ans;
    }
};