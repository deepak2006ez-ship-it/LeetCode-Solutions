class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>prefixSum(n,0);
        int ans=0;
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(prefixSum[i]==goal){
                ans++;
            }
            int val =prefixSum[i]-goal;
            if(mp.find(val)!=mp.end()){
                ans+=mp[val];
            }
            mp[prefixSum[i]]++;
        }
        return ans;
        
    }
};