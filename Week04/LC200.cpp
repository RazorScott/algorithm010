class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& a, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size()) return;
        if (visited[i][j]) return;
        if (a[i][j] == '1') {
            visited[i][j] = true;
            dfs(i-1, j, a, visited);
            dfs(i+1, j, a, visited);
            dfs(i, j-1, a, visited);
            dfs(i, j+1, a, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i< n; ++i) {
            for (int j = 0; j< m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};
