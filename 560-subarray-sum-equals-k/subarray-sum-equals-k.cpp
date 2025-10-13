class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, prefixSum = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case for subarrays starting from index 0
        
        for (int num : nums) {
            prefixSum += num;
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }
            prefixCount[prefixSum]++;
        }
        return count;
    }
};
