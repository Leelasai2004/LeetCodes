class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        string comp="";
        int l=0,r=0;
        while(r<n){
            // cout<<l<<" "<<r<<" ";
            while(r<n && s[l]==s[r] && r-l+1<9){
                r++;
            }
            // cout<<l<<" "<<r<<" ";
            if(r-l+1<=9 && s[l]==s[r]){
                comp+=(to_string(r-l+1));
                comp+=s[l];
            }
            else if(s[l]!=s[r]){
                r--;
                comp+=(to_string(r-l+1));
                comp+=s[l];
            }
            r++;
            l=r;
        }
        return comp;
    }
};