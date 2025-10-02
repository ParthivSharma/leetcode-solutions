class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> num2;
        num2.push_back(nums[0]);  

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                num2.push_back(nums[i]);  
            }
        }
 
        for (int j = 0; j < num2.size(); j++) {
            nums[j] = num2[j];
        }

        return num2.size(); 
    }
};
