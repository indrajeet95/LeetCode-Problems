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