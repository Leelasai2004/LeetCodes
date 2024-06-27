class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        deque<array<int,3>> dq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    dq.push_back({i,j,0});
                }
            }
        }
        vector<vector<int>> time(n,vector<int>(m,-1));
        while(!dq.empty()){
            array<int,3> u=dq.front();
            dq.pop_front();
            // cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<'\n';
            time[u[0]][u[1]]=u[2];
            // grid[u[0]][u[1]]=3;
            for(int i=0;i<4;i++){
                int nx=u[0]+dx[i],ny=u[1]+dy[i];
                if(nx>=n || ny>=m || nx<0 || ny<0 || grid[nx][ny]!=1) continue;
                grid[nx][ny]=3;
                dq.push_back({nx,ny,u[2]+1});
            }
        }   
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1 || grid[i][j]==3){
                    if(time[i][j]==-1) return -1;
                    ans=max(ans,time[i][j]);
                }
            }
            // cout<<'\n';
        }
        return ans;
    }
};