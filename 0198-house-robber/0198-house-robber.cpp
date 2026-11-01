class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev1=0;
        int result=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            result=max(prev2+nums[i],prev1);
            ans=max(result,ans);
            prev2=prev1;
            prev1=result;
        }
        return ans;
        
    }
};