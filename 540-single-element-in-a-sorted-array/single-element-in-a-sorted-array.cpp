class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even (for easier pair checking)
            if (mid % 2 == 1) mid--;

            // If pair is valid, single element is on right side
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } 
            // Else, single element is on left side (including mid)
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};
