class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int left=0;
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            while(left<n && mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;

        }
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
        
    }
};