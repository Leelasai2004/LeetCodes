class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        std::reverse(s.begin(),s.end());
        long ans=stol(s);
        // cout<<ans<<'\n';
        if(ans<INT_MIN || ans>INT_MAX){
            return 0;
        }
        if(x<0){
            return -ans;
        }
        else{
            return ans;
        }
    }
};