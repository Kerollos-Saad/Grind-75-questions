class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        
        // Add all zeros to queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // BFS from all zeros
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return dist;
    }
};