class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double ans = windowSum / k;

        int left = 0;
        int right = k - 1;

        while (right < nums.size() - 1) {
            windowSum = windowSum - nums[left] + nums[right + 1];

            left++;
            right++;

            ans = max(ans, windowSum / k);
        }

        return ans;
    }
};