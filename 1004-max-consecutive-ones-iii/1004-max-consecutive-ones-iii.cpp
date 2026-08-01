class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                mp[nums[right]]++;
            }
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};