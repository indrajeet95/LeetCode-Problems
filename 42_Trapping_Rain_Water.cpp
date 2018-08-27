class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i=1;i<height.size()-1;i++)
        {
            int max_l = 0, max_r = 0;
            for(int j=i;j>=0;j--)
                max_l = max(max_l,height[j]);
            for(int j=i;j<height.size();j++)
            {
                max_r = max(max_r,height[j]);                
            }
            ans += min(max_l,max_r) - height[i];
            cout << ans << endl;
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int> lmax(size);
        vector<int> rmax(size);
        lmax[0] = height[0];
        rmax[size-1] = height[size-1];
        for(int i=1;i<size;i++)
            lmax[i] = max(lmax[i-1],height[i]);
        for(int i=size-2;i>=0;i--)
            rmax[i] = max(rmax[i+1],height[i]);
        for(int i=1;i<size-1;i++)
            ans += min(lmax[i],rmax[i]) - height[i];
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0,rmax = 0;
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left]>=lmax)
                    lmax = height[left];
                else
                    ans += lmax - height[left];
                left++;
            }
            else
            {
                if(height[right]>=rmax)
                    rmax = height[right];
                else
                    ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};
