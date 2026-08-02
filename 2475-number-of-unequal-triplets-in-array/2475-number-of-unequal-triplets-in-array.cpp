//refer note
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int x : nums)
            freq[x]++;

        int left = 0;
        int ans = 0;
        int n = nums.size();

        for(auto &[num, cnt] : freq) {
            int right = n - left - cnt;
            ans += left * cnt * right;
            left += cnt;
        }

        return ans;
    }
};