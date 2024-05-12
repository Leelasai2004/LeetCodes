class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=INT_MIN;
       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int opt=INT_MIN;
            if(j+1<m){
                opt=max(opt,grid[i][j+1]);
            }
            if(i+1<n){
                opt=max(opt,grid[i+1][j]);
            }
            if(opt>INT_MIN){
                ans=max(ans,opt-grid[i][j]);
                grid[i][j]=max(grid[i][j],opt);
            }
        }
       }
       return ans; 
    }
};