class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size(), false);
        seen[0] = true;
        stack<vector<int>> keys;
        keys.push(rooms[0]);
        while(!keys.empty())
        {
            vector<int> holder = keys.top();
            keys.pop();
            for(auto key : holder)
            {
                if(!seen[key])
                {
                    seen[key] = true;
                    keys.push(rooms[key]);
                }
            }
        }
        bool res;
        for(int i=0; i<seen.size(); i++)
        {
            if(seen[i] == false)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size(), false);
        seen[0] = true;
        stack<int> keys;
        keys.push(0);
        while(!keys.empty())
        {
            int curr_key = keys.top();
            keys.pop();
            for(auto key : rooms[curr_key])
            {
                if(!seen[key])
                {
                    seen[key] = true;
                    keys.push(key);
                }
            }
        }
        bool res;
        for(int i=0; i<seen.size(); i++)
        {
            if(seen[i] == false)
                return false;
        }
        return true;
    }
};
