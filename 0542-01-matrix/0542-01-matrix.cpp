class Solution {
public:
    vector<int> dx={-1,0,0,1};
    vector<int> dy={0,1,-1,0};
    bool is_valid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m ){
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=dx[i]+x,ny=y+dy[i];
                if(is_valid(nx,ny,n,m)){
                    if(dist[x][y]+1<dist[nx][ny]){
                        q.push({nx,ny});
                        dist[nx][ny]=dist[x][y]+1;
                    }
                }
            }
        }
        return dist; 
    }
};