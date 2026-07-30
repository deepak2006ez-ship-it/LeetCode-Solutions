class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int targetSumWindow=0;
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++){
            targetSumWindow+=nums[i];
            if(targetSumWindow>=target){
                ans=min(ans,i+1);
                break;
            }
            if(i==(n-1)){
                return 0;
            }
        }
        int left=0;
        int right=ans-1;
        if(right==n-1){
            while(targetSumWindow>=target ){
                targetSumWindow=targetSumWindow-nums[left];
                if(targetSumWindow>=target){

                    ans=min(ans,(right)-left);
                }
                left++;
            }
        }
        while(right<n-1){
            targetSumWindow=targetSumWindow-nums[left]+nums[right+1];
            while(targetSumWindow>=target){
                left++;
                targetSumWindow=targetSumWindow-nums[left];
                ans=min(ans,(right+1)-left+1);
            }
            left++;
            right++;

        }
        return ans;
        
    }
};