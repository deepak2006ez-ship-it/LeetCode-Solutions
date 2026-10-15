class Solution {
public:
    void isHelper(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j){
        int r=grid.size();
        int c=grid[0].size();
        if(i>=r||j>=c|| i<0 ||j<0||   grid[i][j]=='0'|| vis[i][j]==true){
            return;
        }
       int element=grid[i][j];
       vis[i][j]=true;
       isHelper(grid,vis,i+1,j);
       isHelper(grid,vis,i,j+1);
       isHelper(grid,vis,i-1,j);
       isHelper(grid,vis,i,j-1);



    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int r = grid.size();
        int c=grid[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j <grid[i].size(); j++) {
                if(!vis[i][j] && grid[i][j]=='1'){
                    isHelper(grid,vis,i,j);
                    cout<<"running";
                    ans++;
                }
               
            }
        }
        return ans;
    }
};