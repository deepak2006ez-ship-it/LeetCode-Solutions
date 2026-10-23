class Solution {
public:
    vector<int>rank,par;
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);

    }
    void unionByRank(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB){return;}
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(i);
        }
        for(int i=0;i<n;i++){
            for(auto &v:adjList[i]){
                unionByRank(i,v);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(par[i]==i){
                ans++;
            }
        }
        return ans;
    }
};