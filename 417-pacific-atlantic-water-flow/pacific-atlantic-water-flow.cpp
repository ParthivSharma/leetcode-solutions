class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // DFS from Pacific borders
        for (int i = 0; i < m; i++) dfs(heights, pacific, i, 0);
        for (int j = 0; j < n; j++) dfs(heights, pacific, 0, j);

        // DFS from Atlantic borders
        for (int i = 0; i < m; i++) dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; j++) dfs(heights, atlantic, m - 1, j);

        // Collect cells reachable by both
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (visited[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue;
            dfs(heights, visited, nr, nc);
        }
    }
};
