//refer notes
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        long long totalSum = prefixSum[n - 1];
        int need = totalSum % p;

        if (need == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;   

        int ans = n;

        for (int i = 0; i < n; i++) {

            int currRem = prefixSum[i] % p;

            int target = (currRem - need + p) % p;

            if (mp.find(target) != mp.end()) {
                ans = min(ans, i - mp[target]);
            }

            mp[currRem] = i;
        }

        return (ans == n) ? -1 : ans;
    }
};