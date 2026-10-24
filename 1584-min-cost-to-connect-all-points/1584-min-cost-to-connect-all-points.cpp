class Edge {
public:
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
    bool operator<(const Edge& other) const { return this->wt < other.wt; }
};
class Graph {
public:
    int n;
    vector<int> rank, par;
    vector<Edge> edges;
    Graph(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            rank.push_back(0);
            par.push_back(i);
        }
    }
    void addEdge(int u, int v, int wt) { edges.push_back(Edge(u, v, wt)); }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionByRank(int u, int v) {
        int parA = find(u);
        int parB = find(v);
        if (parA == parB) {
            return;
        }
        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }
    int kruskal() {
        sort(edges.begin(), edges.end());
        int count = 0;
        int mstCst = 0;

        for (int i = 0; i < edges.size() && count < n - 1; i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);
            if (parU != parV) {
                unionByRank(e.u, e.v);
                mstCst += e.wt;
                count++;
            }
        }
        return mstCst;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        Graph g(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = abs(points[j][0] - points[i][0]);
                int y = abs(points[j][1] - points[i][1]);
                int dist = x + y;
                g.addEdge(i, j, dist);
            }
        }

        return g.kruskal();
    }
};