class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int nc) {
        int c = image[sr][sc];
       if(c!=nc) dfs(image, sr, sc, c, nc);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int c, int nc) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size()) {
            return;
        }
        if (image[i][j] != c) {
            return;
        }
        image[i][j] = nc;
        if (i + 1 < image.size())
            dfs(image, i + 1, j, c, nc);
        if (i >= 1)
            dfs(image, i - 1, j, c, nc);
        if (j + 1 < image[0].size())
            dfs(image, i, j + 1, c, nc);
        if (j >= 1)
            dfs(image, i, j - 1, c, nc);
    }
};