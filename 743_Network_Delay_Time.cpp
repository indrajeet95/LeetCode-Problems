class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>>& g, int src){
        int n = g.size();
        vector<int> ret(n, -1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<void>> q;
        q.push({0,src});
        while(!q.empty()){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<void>> qcopy = q;
            /*while(!qcopy.empty())
            {
                cout << qcopy.top().first << " " << qcopy.top().second << " ";
                qcopy.pop();
            }*/
            //cout << endl;
            auto x = q.top(); q.pop();
            int dist = x.first, u = x.second;
            if(ret[u] != -1)
                continue;
            ret[u] = dist;
            //iterate over all children of u and add the net distance to the queue
            for(auto v : g[u])
                q.push({v.second + dist, v.first});
        }
        return ret;
    }
    
    int networkDelayTime(vector<vector<int>>& a, int n, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0; i<a.size(); i++){
            int u = a[i][0] - 1, v = a[i][1] - 1, c = a[i][2];
            g[u].push_back({v,c});
        }
       for(int i=0; i<g.size(); i++){
            //cout << "Source: " << i << " ";
            for(int j=0; j<g[i].size(); j++)
            {
                //cout << "Dest: " <<g[i][j].first << " Dist: " << g[i][j].second << "; ";
            }
            //cout << endl;
        }
        auto ret = dijkstra(g, k-1);
        int hi = 0;
        for(int i=0; i<n; i++){
            if(ret[i] == -1) return -1;
            hi = max(hi, ret[i]);
        }
        return hi;
    }
};