class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[l] , nums[i]);
                l++;
            }
        }
        
    }
};