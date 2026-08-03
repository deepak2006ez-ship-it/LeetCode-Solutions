class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int ans=0;
        int n=nums.size();
        long long windowProduct=1;
        if(k<=1){
            return 0;//mistake made
        }
        for(int right=0;right<n;right++){
            windowProduct*=nums[right];
            while(left <n && windowProduct>=k){
                windowProduct/=nums[left];
                left++;
            }
             ans+=(right-left+1);

        }
        return ans;
    }
};