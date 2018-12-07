class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int r = 0;
        int c = 0;
        int index = 0;
        int row_dir[4] = {0,1,0,-1};
        int col_dir[4] = {1,0,-1,0};
        for(int i=0; i< n*n; i++)
        {
            res[r][c] = i+1;
            int rr = r + row_dir[index];
            int cc = c + col_dir[index];
            if(rr>=0 && rr<n && cc>=0 && cc<n && res[rr][cc]==0)
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
        cout << r << " " << c;
        return res;
    }
};