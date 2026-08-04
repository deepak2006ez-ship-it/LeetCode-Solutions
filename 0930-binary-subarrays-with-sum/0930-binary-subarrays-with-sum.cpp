//note
class Solution {
public:
    int AtMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int left = 0;
        int windowSum = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            while (windowSum > goal) {
                windowSum -= nums[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);
    }
};