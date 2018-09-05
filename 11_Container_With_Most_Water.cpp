class Solution {
public:
    int maxArea(vector<int>& height) {
        //O(n^2) solution
        int maxarea = 0;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
                maxarea = max(maxarea,(j-i)*min(height[i],height[j]));
        }
        return maxarea;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r)
        {
            maxarea = max(maxarea,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};
