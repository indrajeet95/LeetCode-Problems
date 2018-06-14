class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //left range and right range
        //i and j, i represents
        int gassum = 0;
        if(gas.size()==0 || cost.size()==0 || gas.size() != cost.size())
            return -1;
        int i=0;
        int j = gas.size();
        int curr=0;
        while(i!=j)
        {
            gassum += gas[curr] - cost[curr];
            if(gassum>=0)
            {
                i=i+1;
                curr = i;
            }
            else
            {
                j=j-1;
                curr = j;
            }
        }
        if(gassum>=0)
            return j%(gas.size());
        else
            return -1;
    }
};
