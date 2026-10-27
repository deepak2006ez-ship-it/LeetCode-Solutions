class Solution {
public:
    int time;
    vector<int>dt,low;
    void bridge(int u,int parU,vector<vector<int>>&adjList,vector<vector<int>>&ans){
        dt[u]=low[u]=++time;
        for(auto &v:adjList[u]){
            if(dt[v]==-1){
                bridge(v,u,adjList,ans);
                low[u]=min(low[u],low[v]);
                if(low[v]>dt[u]){
                    ans.push_back({u,v});
                }

            }else if(v!=parU){
                low[u]=min(low[u],dt[v]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjList(n);
        vector<vector<int>>ans;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        time=0;
        dt.assign(n,-1);
        low.assign(n,-1);
        for(int i=0;i<n;i++){
            if(dt[i]==-1){
                bridge(i,-1,adjList,ans);

            }
        }
        return ans;
    }
};