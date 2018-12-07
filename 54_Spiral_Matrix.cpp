class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        int r = 0;
        int c = 0;
        int index = 0;
        int row_dir[4] = {0, 1, 0, -1};
        int col_dir[4] = {1, 0, -1, 0};
        for(int i=0; i< rows*cols; i++)
        {
            res.push_back(matrix[r][c]);
            visited[r][c] = true;
            int rr = r + row_dir[index];
            int cc = c + col_dir[index];
            if(rr>=0 && rr<rows && cc>=0 && cc<cols && !visited[rr][cc])
            {
                r = rr;
                c = cc;
            }
            else
            {
                index = (index + 1)%4;
                r += row_dir[index];
                c += col_dir[index];
            }
        }
        return res;
    }
};