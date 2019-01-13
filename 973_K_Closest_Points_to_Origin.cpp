/*class Foo {
    private:
        pair<float, vector<int>> holder;
};*/
class Compare {
    public:
        bool operator() (pair<float, vector<int>> A, pair<float, vector<int>> B) {
            return A.first > B.first;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue <pair<float, vector<int>>,vector<pair<float, vector<int>>>, Compare> holder;
        //priority_queue <Foo,vector<Foo>, Compare> holder;
        for(auto point : points)
        {
            float distance = cal_distance(point);
            //cout << distance << endl;
            //Foo a = make_pair(distance, point);
            holder.push(make_pair(distance, point));
        }
        //cout << holder.top().first << " "<<holder.top().second[0] << endl;
        while(K>0)
        {
            res.push_back(holder.top().second);
            holder.pop();
            K--;
        }
        return res;
    }
    float cal_distance(vector<int> point)
    {
        int a = point[0];
        int b = point[1];
        return pow(pow(a,2) + pow(b,2), 0.5);
    }
};