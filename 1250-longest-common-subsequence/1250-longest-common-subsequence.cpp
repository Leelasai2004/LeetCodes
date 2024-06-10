class Solution {
public:
    string s,t;
    int f( vector<vector<int>> &dp,int i,int j){
        if(i>=s.size() || j>=t.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return 1+f(dp,i+1,j+1);
        }
        return dp[i][j]=max(f(dp,i+1,j),f(dp,i,j+1));
    }
    int longestCommonSubsequence(string s, string t) {
        this->s=s,this->t=t;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(dp,0,0);
    }
};