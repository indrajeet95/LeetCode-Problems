class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int maxp = 0, res = 0;
        for(int i=0;i<profit.size();i++)
            jobs.push_back(make_pair(difficulty[i],profit[i]));
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int j = 0;
        for(int i=0;i<worker.size();i++)
        {
            while(j<profit.size() && worker[i]>=jobs[j].first)
                maxp = max(maxp,jobs[j++].second);
            res += maxp;
        }
        return res;
    }
};