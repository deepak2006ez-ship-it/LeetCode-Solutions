class Solution {
public:
    // memoisation
    int fibDP(int n,vector<int>&dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=fibDP(n-1,dp)+fibDP(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return fibDP(n,dp);
    }
};