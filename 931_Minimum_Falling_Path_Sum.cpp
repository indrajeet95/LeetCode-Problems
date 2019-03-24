//DP - ON OWN
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows == 0)
            return 0;
        int cols = A[0].size();
        vector<vector<int>> holder(rows, vector<int> (cols, 0));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols;j++) {
                holder[i][j] = A[i][j]; 
            }
        }
        cout << "Holder" << endl;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols;j++) {
                cout << holder[i][j] << " ";                
            }
            cout << endl;
        }
        for(int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j < cols; j++) {
                int base = holder[i][j];
                holder[i][j] += holder[i+1][j];
                if(j-1>=0)
                    holder[i][j] = min(holder[i][j], base + holder[i+1][j-1]);
                if(j+1<cols)
                    holder[i][j] = min(holder[i][j], base + holder[i+1][j+1]);
            }
        }
        cout << "Holder" << endl;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols;j++) {
                cout << holder[i][j] << " ";               
            }
            cout << endl;
        }
        
        int res = holder[0][0];
        for(int i=1; i<cols; i++) {
            if(holder[0][i] < res)
                res = holder[0][i];
        }
        return res;
    }
    
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows == 0)
            return 0;
        int cols = A[0].size();
        for(int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j < cols; j++) {
                int base = A[i][j];
                A[i][j] += A[i+1][j];
                if(j-1>=0)
                    A[i][j] = min(A[i][j], base + A[i+1][j-1]);
                if(j+1<cols)
                    A[i][j] = min(A[i][j], base + A[i+1][j+1]);
            }
        }
        int res = A[0][0];
        for(int i=1; i<cols; i++) {
            if(A[0][i] < res)
                res = A[0][i];
        }
        return res;
    }

};
