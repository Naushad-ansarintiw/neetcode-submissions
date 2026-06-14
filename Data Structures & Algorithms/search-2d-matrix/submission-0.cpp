class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        int trueRow = -1; 
        int l=0, r=n-1; 
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]) {
                trueRow = mid; 
                break;
            }
            else if(target > matrix[mid][m-1]) l = mid + 1;
            else r = mid -1; 
        }
        if(trueRow == -1) return false; 
        l=0, r=m-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(target == matrix[trueRow][mid]) return true;
            else if(target > matrix[trueRow][mid]) l = mid + 1; 
            else r = mid - 1;
        }
        return false;
    }
};
