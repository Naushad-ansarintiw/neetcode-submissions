class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q; 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,{j, 0}});
                    vis[i][j] = 1; 
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0}; 
        int dc[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            int r = q.front().first; 
            int c = q.front().second.first; 
            int step = q.front().second.second; 
            q.pop(); 

            for(int i=0; i<4; i++) {
                int newr = r + dr[i]; 
                int newc = c + dc[i]; 
                if(newr>=0 && newr < n && newc >=0 && newc < m && !vis[newr][newc] 
                && grid[newr][newc] == 2147483647) {
                    q.push({newr, {newc, step+1}});
                    vis[newr][newc] = 1; 
                    grid[newr][newc] = step + 1; 
                }
            }
        }
        
    }
};
