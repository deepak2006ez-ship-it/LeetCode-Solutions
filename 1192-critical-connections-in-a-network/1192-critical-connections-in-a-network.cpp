class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<vector<int>>& adj,
             vector<vector<int>>& cc) {

        dt[u] = low[u] = ++time;

        for (auto& v : adj[u]) {
            if (dt[v] == -1) {
                // Visit the unvisited child
                dfs(v, u, adj, cc);

                // Update low-link value
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > dt[u]) {
                    cc.push_back({u, v});//Because the inner type is vector<int>. C++ can use the initializer-list constructor to create a vector containing those integers.
                }
            }
            else if (v != parU) {
                // Back edge to an already visited node
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adjList(n);
        vector<vector<int>> ans;

        // Build the undirected graph
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        time = 0;
        dt.assign(n, -1);
        low.assign(n, -1);

        // Handle disconnected components
        for (int i = 0; i < n; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, adjList, ans);
            }
        }

        return ans;
    }
};