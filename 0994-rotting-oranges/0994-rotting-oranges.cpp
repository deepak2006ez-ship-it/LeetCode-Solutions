class Solution {
public:
    int ans = 0;
    void calculateRotten(vector<vector<int>>& grid,
                         vector<vector<bool>>& visited, queue<pair<int,int>>& q, int r,
                         int c) {
        q.push({-1, -1});
        while (q.size()>1) {
            bool isOneExistNearby=false;

            while (q.front().first != -1) {
                int l = q.front().first;
                int m = q.front().second;
                q.pop();
                if (l + 1 < r && (!visited[l + 1][m] && grid[l + 1][m] == 1)) {
                    visited[l + 1][m] = true;
                    q.push({(l + 1), m});
                    isOneExistNearby = true;
                }
                if (l - 1 >= 0 && (!visited[l - 1][m] && grid[l - 1][m] == 1)) {
                    visited[l - 1][m] = true;
                    q.push({(l - 1), m});
                    isOneExistNearby = true;
                }
                if (m + 1 < c && (!visited[l][m + 1] && grid[l][m + 1] == 1)) {
                    visited[l][m + 1] = true;
                    q.push({(l), m + 1});
                    isOneExistNearby = true;
                }
                if (m - 1 >= 0 && (!visited[l][m - 1] && grid[l][m - 1] == 1)) {
                    visited[l][m - 1] = true;
                    q.push({l, (m - 1)});
                    isOneExistNearby = true;
                }
            
            }
            q.push({-1,-1});
            if(isOneExistNearby){
                ans++;
            }
            q.pop();
            
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        calculateRotten(grid,visited,q,r,c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};