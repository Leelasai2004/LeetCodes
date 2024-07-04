class Solution {
public:
vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    bool is_valid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || j >= m || i >= n) {
            return false;
        }
        return true;
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<array<int, 2>> q;
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans+=board[i][j];
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 1) {
                    q.push({i, j});
                     vis[i][j]=2;
                }
            }
        }
        int steps=0;
               while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1];
        // if(x==1 && y==4)    cout << x << " " << y << " " << vis[x][y] << " " << board[x][y] << 'n';
            steps++;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (is_valid(nx, ny, n, m)) {
                    if (board[nx][ny] == 1 && vis[nx][ny] != 2) {
                        q.push({nx, ny});
                        vis[nx][ny] = 2;
                    }
                }
            }
        }

        cout<<steps<<'\n';
        ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && vis[i][j] ==0) {
                   ans++;
                }
                // board[i][j]='0'+vis[i][j];
            }
        }
        return ans;
    }
};