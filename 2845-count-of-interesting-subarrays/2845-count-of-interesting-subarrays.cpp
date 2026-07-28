class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        int noOfDivisible=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k){
                noOfDivisible++;
            }
            int val = (noOfDivisible % modulo - k + modulo) % modulo;
            if(mp.find(val)!=mp.end()){
                ans+=mp[val];
            }
            mp[noOfDivisible%modulo]++;

        }
        return ans;
    }
};