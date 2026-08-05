class Solution {
public:
    int AtMost(vector<int>& nums, int k){
        int left=0;
        int ans=0;
        int n=nums.size();
        int window=0;
        for(int right=0;right<n;right++){
            if(nums[right]%2!=0){
                window+=1;
            }
            while(window>k){
                if(nums[left]%2!=0){
                    window-=1;
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMost(nums,k)-AtMost(nums,k-1);
        
    }
};