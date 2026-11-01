class Solution {
public:
    int climbStairs(int n) {
        if(n==1 ||n==2){
            return n;
        }
        int prev2=1;//n-2
        int prev1=2;//n-1
        int result=prev1;//we start result from prev1 beacuse result indicate ans at that point so suppose 2 stair then ans is prev1
        for(int i=3;i<=n;i++){
            result=prev1+prev2;
            prev2=prev1;
            prev1=result;
        }
        return result;
        
    }
};