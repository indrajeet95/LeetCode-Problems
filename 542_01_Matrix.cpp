class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if(r == 0)
            return matrix;
        int c = matrix[0].size();
        vector<vector<int>> res(r, vector<int> (c, INT_MAX));
        queue<pair<int,int>> h;
        for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
            {
                if(matrix[i][j] == 0)
                {
                    res[i][j] = 0;
                    h.push(make_pair(i,j));
                }
            }
        }
        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!h.empty())
        {
            pair<int,int> current = h.front();
            h.pop();
            for(int i=0; i<4; i++)
            {
                int new_curr_a = current.first + dir[i][0];
                int new_curr_b = current.second + dir[i][1];
                if(new_curr_a >= 0 && new_curr_b >= 0 && new_curr_a < r && new_curr_b < c)
                {
                    if(res[new_curr_a][new_curr_b] > res[current.first][current.second] + 1)
                    {
                        res[new_curr_a][new_curr_b] = res[current.first][current.second] + 1;
                        h.push(make_pair(new_curr_a,new_curr_b));
                    }                    
                }
            }
        }
        return res;
    }
};