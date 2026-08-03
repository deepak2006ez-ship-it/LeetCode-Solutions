class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int ans=0;
        int n=nums.size();
        long long windowProduct=1;
        for(int right=0;right<n;right++){
            windowProduct*=nums[right];
            while(left <n && windowProduct>=k){
                windowProduct/=nums[left];
                left++;
            }
            ans+=1;
            ans+=(right-left);//it is added beacuse right most element can form subaray with evry elemnt execpt starting beacuse its alraedy counted

        }
        return ans;
    }
};