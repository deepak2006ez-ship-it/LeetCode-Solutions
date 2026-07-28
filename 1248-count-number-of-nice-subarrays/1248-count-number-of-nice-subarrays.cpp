class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                count++;
            }
            int val=count-k;
            if(mp.find(val)!=mp.end()){
                ans+=mp[val];
            }
            mp[count]++;

        }
        return ans;
    }
};