class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), num = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    num++;
                    markIslands(grid, visited, i, j);
                }
            }
        }
        return num;
    }
private: 
    void markIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int m = grid.size(), n = grid[0].size();
        if (r - 1 >= 0 && grid[r - 1][c] == '1' && !visited[r - 1][c])
            markIslands(grid, visited, r - 1, c);
        if (r + 1 < m && grid[r + 1][c] == '1' && !visited[r + 1][c])
            markIslands(grid, visited, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1' && !visited[r][c - 1])
            markIslands(grid, visited, r, c - 1);
        if (c + 1 < n && grid[r][c + 1] == '1' && !visited[r][c + 1])
            markIslands(grid, visited, r, c + 1);
    }
};