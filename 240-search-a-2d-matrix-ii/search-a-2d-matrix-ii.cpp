class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            int value=matrix[row][col];
            if(value==target) return true;
            else if(value<target) row++;
            else col--;
        }
        return false;
    }
};