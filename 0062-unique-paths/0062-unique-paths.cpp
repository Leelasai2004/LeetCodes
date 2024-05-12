class Solution {
public:
    int combinatorics(int m ,int n){
        long long res=1;
        long long N=m+n-2;
        long long R=m-1;
        for(long long i=1;i<=R;i++){
            res=res*(N-R+i)/i;
        }
        return (int)res;
    }
    int helper(vector<vector<int>> &dp,int i,int j){
         if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       
        return dp[i][j]=helper(dp,i-1,j)+helper(dp,i,j-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i!=0){
        //             dp[i][j]+=dp[i-1][j];
        //         }
        //         if(j!=0){
        //             dp[i][j]+=dp[i][j-1];
        //         }
        //     }
        // }
        vector<int> prev(n);
        prev[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int present=0;
                if(i==0 && j==0){
                    continue;
                }
                if(j>0){
                    present+=prev[j-1];
                }
                if(i>0){
                    present+=prev[j];
                }
                // cout<<present<<" "<<col<<'\n';
                prev[j]=present;
            }
        }
        // return prev[n-1];         //space-optimization
        // return helper(dp,m-1,n-1);  // memoization
        // return dp[m-1][n-1];        // tabulation
        return combinatorics(m,n);
    }
};