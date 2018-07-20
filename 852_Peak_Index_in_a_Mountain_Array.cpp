class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i =0;
        while(A[i] < A[i+1])
        {
            i++;
        }
        return i;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0;
        int h = A.size()-1;
        while(low<h)
        {
            int mid = (h - low)/2 + low;
            if(A[mid] < A[mid+1])
                low = mid+1;
            else
                h = mid;
        }
        return low;
    }
};