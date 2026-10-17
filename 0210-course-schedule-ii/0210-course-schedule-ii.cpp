class Solution {
public:
    vector<int> ans;
    void topologicalSort(int curr, vector<int>* adjList, vector<bool>& visited,
                         stack<int>& s) {
        visited[curr] = true;
        for (auto& v : adjList[curr]) {
            if (!visited[v]) {
                topologicalSort(v, adjList, visited, s);
            }
        }
        s.push(curr);
    }
    bool isCycleExist(vector<int>* adjList, int curr, vector<bool>& visited,
                      vector<bool>& path) {
        visited[curr] = true;
        path[curr] = true;

        for (auto& v : adjList[curr]) {
            if (!visited[v]) {
                if (isCycleExist(adjList, v, visited, path)) {
                    return true;
                }
            } else if (path[v]) {
                return true;
            }
        }

        path[curr] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        vector<int>* adjList = new vector<int>[numCourses];

        for (int i = 0; i < n; i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCycleExist(adjList, i, visited, path)) {
                    return ans;
                }
            }
        }
        vector<bool> vis(numCourses, false);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topologicalSort(i,adjList, vis, s);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};