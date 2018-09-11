class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        int boats  = 0;
        while(i<=j)
        {
            if(people[i] + people[j] <= limit)
            {
                boats++;
                i++;
                j--;
            }
            else if(people[j] <= limit)
            {
                boats++;
                j--;            
            }
        }
        return boats;
    }
};
