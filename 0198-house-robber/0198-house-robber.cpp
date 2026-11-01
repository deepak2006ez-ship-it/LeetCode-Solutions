class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev1=0;
        int result=0;
        for(int i=0;i<nums.size();i++){
            result=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=result;
        }
        return prev1;
        
    }
};