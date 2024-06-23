class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        int width = maxCol - minCol + 1;
        int height = maxRow - minRow + 1;
        int area = width * height;

        return area;
    }
};