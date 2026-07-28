//bucket concept
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // bits seen once
        int ones = 0;

        // bits seen twice
        int twos = 0;

        for (int num : nums) {

            // add new bits to ones
            ones = (ones ^ num) & ~twos;//nums will go to ones if not in twos

            // add new bits to twos
            twos = (twos ^ num) & ~ones;//nums will go to two if it is in ones
        }

        // remaining bits are single number
        return ones;
    }
};