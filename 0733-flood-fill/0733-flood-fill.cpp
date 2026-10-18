class Solution {
public:
    void helper(vector<vector<int>>& image,  int color,int i,int j,vector<vector<bool>>&vis,int key){
        int r=image.size();
        int c=image[0].size();
        if(i<0 || i>=r||j<0 ||j>=c|| vis[i][j]  || image[i][j]!=key){
            return;
        }
        //i represent row and j represnt col
        image[i][j]=color;
        vis[i][j]=true;
        helper(image,color,i+1,j,vis,key);
        helper(image,color,i-1,j,vis,key);
        helper(image,color,i,j+1,vis,key);
        helper(image,color,i,j-1,vis,key);


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        int key=image[sr][sc];
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(!vis[i][j] && image[i][j]==1){
        //             helper(image,sr,sc,color,i,jvis);
        //         }
        //     }
        // }
         helper(image,color,sr,sc,vis,key);


        return image;
    }
};