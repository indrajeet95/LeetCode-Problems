// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        while(i<j)
        {
            int mid = i+(j-i)/2;
            if(isBadVersion(mid) == 1)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};