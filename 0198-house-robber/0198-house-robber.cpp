class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
                }        
      int prev2=nums[0];
      int prev1=max(nums[0],nums[1]);
        int result=prev1;
        for(int i=2;i<n;i++){
            result=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=result;
        }
        return prev1;
    }
};