class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> car;
        for(int i=0;i<position.size();i++)
            car[position[i]] = (double)(target-position[i])/speed[i];
        int ans = 0;
        double curr = 0;
        for(auto it=car.rbegin();it!=car.rend();it++)
            if(it->second > curr)
            {
                curr = it->second;
                ans++;
            }
        return ans;
    }
};