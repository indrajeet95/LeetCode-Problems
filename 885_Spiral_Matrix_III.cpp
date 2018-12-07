class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int row_dir[4] = {0, 1, 0, -1};
        int col_dir[4] = {1, 0, -1, 0};
        res.push_back({r0,c0});
        if(R*C == 1)
            return res;
        for(int k = 1; k < 2*(R+C); k += 2)
        {
            for(int dir = 0; dir<4; dir++)
            {
                int ik = k + (dir/2);
                for(int j=0; j<ik;j++)
                {
                    r0 += row_dir[dir];
                    c0 += col_dir[dir];
                    if(r0>=0 && r0<R && c0>=0 && c0<C)
                        res.push_back({r0,c0});
                    if(res.size() == R*C)
                        return res;
                }
            }
        }
        
    }
};