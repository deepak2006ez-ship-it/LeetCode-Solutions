class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        int ans = 0;
        while (q.size() > 0) {
            int l = q.front().first.first;
            int m = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans, t);
            if (l + 1 < r && (!visited[l + 1][m] && grid[l + 1][m] == 1)) {
                visited[l + 1][m] = true;
                q.push({{(l + 1), m},t+1});
            }
            if (l - 1 >= 0 && (!visited[l - 1][m] && grid[l - 1][m] == 1)) {
                visited[l - 1][m] = true;
                q.push({{(l - 1), m},t+1});
            }
            if (m + 1 < c && (!visited[l][m + 1] && grid[l][m + 1] == 1)) {
                visited[l][m + 1] = true;
                q.push({{(l), m + 1},t+1});
            }
            if (m - 1 >= 0 && (!visited[l][m - 1] && grid[l][m - 1] == 1)) {
                visited[l][m - 1] = true;
                q.push({{l, (m - 1)},t+1});
            }
        }
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