class Solution {
public:
    bool in_bound(int x,int y,int n){
        if(x<0 || y<0 || x>=n ||y>=n){
            return false;
        }
        return true;
    }
    vector<int> dx={-1,0,0,1};
    vector<int> dy={0,1,-1,0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        deque<tuple<int,int,int>> dq;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dq.push_front({i,j,0});
                }
            }
        }
        map<pair<int,int>,int> mindis;
        while(!dq.empty()){
            int x=get<0>(dq.front());
            int y=get<1>(dq.front());
            int dis=get<2>(dq.front());
            dq.pop_front();
            if(x<0 || y<0 || x>=n ||y>=n){
                continue;
            }
            for(int i=0;i<4;i++){
                if(in_bound(x+dx[i],y+dy[i],n) && grid[x+dx[i]][y+dy[i]]==0){
                    grid[x+dx[i]][y+dy[i]]+=grid[x][y]+1;
                    dq.push_back({x+dx[i],y+dy[i],dis+1});
                }
            }
        }
        vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
        priority_queue<tuple<int,int,int>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            int x=get<1>(pq.top());
            int y=get<2>(pq.top());
            int cost=get<0>(pq.top());
            vis[x][y]=true;
            pq.pop();
            if(x==n-1 && y==n-1){
                return cost-1;
            }
            for(int i=0;i<4;i++){
                if(in_bound(x+dx[i],y+dy[i],n) && !(vis[x+dx[i]][y+dy[i]])){
                    pq.push({min(cost,grid[x+dx[i]][y+dy[i]]),x+dx[i],y+dy[i]});
                    grid[x+dx[i]][y+dy[i]]*=-1;
                }
            }
        }
        return 0;
    }
};