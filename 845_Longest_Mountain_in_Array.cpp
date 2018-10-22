class Solution {
public:
    // 2 1 4 7 3 2 5
    // 0 1 2 3 4 5 6 
    // base = 2 
    int longestMountain(vector<int>& A) {
        int base = 0;
        int res= 0;
        int n = A.size();
        while(base < n)
        {
            int end = base;
            if(end + 1 < n && A[end+1] > A[end])
            {
                while(end + 1 < n && A[end+1] > A[end])
                    end++;
                if(end + 1 < n && A[end + 1] < A[end])
                {
                    while(end + 1 < n && A[end + 1] < A[end])
                        end++;
                    res = max(end-base+1,res);
                }
            }
            base = max(base+1,end);
        }
        return res;
    }
};