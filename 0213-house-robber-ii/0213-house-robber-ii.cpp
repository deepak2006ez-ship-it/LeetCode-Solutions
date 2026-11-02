class Solution {
public:
    int rob(vector<int>& nums) {
        // 1st dp from start and excluing end
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int prevFirst2 = nums[0];
        int prevFirst1 = max(nums[1], nums[0]);
        int resultFirst = prevFirst1;
        for (int i = 2; i < n - 1; i++) {
            resultFirst = max(prevFirst2 + nums[i], prevFirst1);
            prevFirst2 = prevFirst1;
            prevFirst1 = resultFirst;
        }

        int prevSecond2 = nums[1];
        int prevSecond1 = max(nums[1], nums[2]);
        int resultSecond = prevSecond1;
        for (int i = 3; i < n; i++) {
            resultSecond = max(prevSecond2 + nums[i], prevSecond1);
            prevSecond2 = prevSecond1;
            prevSecond1 = resultSecond;
        }
        return max(resultSecond, resultFirst);
    }
};