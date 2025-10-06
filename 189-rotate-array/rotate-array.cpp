class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         
        int n = nums.size();
        vector<int> num2(n);
        for(int i=0;i<n;i++){
            num2[(i+k)%n]=nums[i];
        }
        
              nums = num2;

        
    }
};