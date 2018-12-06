class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int col = matrix[0].size() - 1;
        int row = 0;
        while(row <= matrix.size() - 1 && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else if(matrix[row][col] < target)
                row++;
        }
        return false;
    }
};