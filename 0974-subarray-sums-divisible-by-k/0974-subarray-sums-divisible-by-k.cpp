//refer notes
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int num : nums) {
            sum += num;

            int rem = ((sum % k) + k) % k;

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};