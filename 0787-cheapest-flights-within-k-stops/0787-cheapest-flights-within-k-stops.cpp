class Solution {
public:
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      
        vector<vector<pair<int,int>>>adjList(n);
        for(int i=0;i<flights.size();i++){
            adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,-1}});//node,{cost,stop}
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto val=q.front();
            int u=val.first;
            int cost=val.second.first;
            int stops =val.second.second;
            q.pop();
            for(auto &neigh:adjList[u]){
                int v=neigh.first;
                int wt=neigh.second;
                if(dist[v]>cost+wt && stops+1<=k){
                    dist[v]=cost+wt;
                    q.push({v,{dist[v],stops+1}});

                }
            }

        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};