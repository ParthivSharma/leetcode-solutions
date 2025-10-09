class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int prevSum = nums[0];
        int start = 0;
        int subStart = 0;
        int end = 0;

        for (int i = 1; i < n; i++) {
            if (prevSum < 0) {
                prevSum = nums[i];
                subStart = i;
            } else {
                prevSum += nums[i];
            }

            // ✅ check maxSum outside the else block
            if (prevSum > maxSum) {
                maxSum = prevSum;
                start = subStart;
                end = i;
            }
        }

        return maxSum;
    }
};
