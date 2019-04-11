class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for(auto ch : tasks)
            map[ch - 'A']++;
        sort(map.begin(), map.end());
        int res = 0;
        while(map[25] > 0) {
            int i = 0;
            while(i <= n) {
                if(map[25] == 0)
                    break;
                if(i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                res++;
                i++;
            }
            sort(map.begin(), map.end());
        }
        return res;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        vector<int> map(26,0);
        for(auto ch : tasks)
            map[ch - 'A']++;
        priority_queue<int> holder;
        for(auto val : map) {
            if(val > 0)
                holder.push(val);
        }
        while(!holder.empty()) {
            int i = 0;
            vector<int> temp;
            while(i <= n) {
                if(!holder.empty()) {
                    if(holder.top() > 1) {
                        temp.push_back(holder.top() - 1);
                        holder.pop();
                    }
                    else
                        holder.pop();
                }
                res++;
                if(holder.empty() && temp.empty())
                    break;
                i++;
            }
            for(int val : temp)
                holder.push(val);
        }
        return res;

    }
};
