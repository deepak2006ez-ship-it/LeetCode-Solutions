class Solution {
public:
    bool isCheck(vector<vector<int>>& grid,int r,int c,int current){
        int n=grid.size();
        if(r<0 || c<0 || r>=n|| c>=n|| grid[r][c]<0 || grid[r][c]!=current){
            return false;
        }
    if(grid[r][c]==n*n-1){
        return true;
    }
        
        int ans1= isCheck(grid,r-2,c+1,current+1);


        int ans2= isCheck(grid,r-2,c-1,current+1);
        


        int ans3= isCheck(grid,r+2,c+1,current+1);
       

        int ans4= isCheck(grid,r+2,c-1,current+1);
     


        int ans5= isCheck(grid,r-1,c+2,current+1);
    
        int ans6= isCheck(grid,r+1,c+2,current+1);
       

        int ans7= isCheck(grid,r-1,c-2,current+1);
        

        int ans8= isCheck(grid,r+1,c-2,current+1);
         
         return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;

        
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isCheck(grid,0,0,0);
        
    }
};