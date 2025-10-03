class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // too small to trap water

        // visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // min-heap: {height, {row, col}}
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<>> pq;

        // Step 1: push boundary cells into heap
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        // Directions for neighbors
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int water = 0;
        int level = 0;

        // Step 2: process cells in heap
        while (!pq.empty()) {
            auto [h, cell] = pq.top(); pq.pop();
            int i = cell.first, j = cell.second;
            level = max(level, h); // current water level is max of boundaries so far

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    if (heightMap[ni][nj] < level) {
                        water += level - heightMap[ni][nj];
                    }
                    pq.push({heightMap[ni][nj], {ni, nj}});
                }
            }
        }

        return water;
    }
    
};