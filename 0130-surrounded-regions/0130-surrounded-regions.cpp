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
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<array<int, 2>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1];
        // if(x==1 && y==4)    cout << x << " " << y << " " << vis[x][y] << " " << board[x][y] << 'n';
            vis[x][y] = 2;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (is_valid(nx, ny, n, m)) {
                    if (board[nx][ny] == 'O' && vis[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] ==0) {
                    board[i][j] = 'X';
                }
                // board[i][j]='0'+vis[i][j];
            }
        }
    }
};