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
                }
            }
        }

        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1];
            // cout << x << " " << y << "\n";
            if(board[x][y]==0){
                q.pop();
                continue;
            }
            board[x][y]=0;
            ans--;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (is_valid(nx, ny, n, m)) {
                    if (board[nx][ny] == 1) {
                        q.push({nx, ny});
                    }
                }
            }
        }
        // int ans=0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (board[i][j] == 1 && vis[i][j] ==0) {
        //            ans++;
        //         }
        //         // board[i][j]='0'+vis[i][j];
        //     }
        // }
        return ans;
    }
};