//DFS

class Solution {
public:
    //finding if there is a cycle in the graph
    // if cycle present, return false
    // else return true
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = createGraph(numCourses, prerequisites);
        vector<bool> todo (numCourses, false);
        vector<bool> done (numCourses, false);
        for(int i=0; i<numCourses; i++) {
            if(!done[i] && !aCyclic(g, todo, done, i))
                return false;
        }
        return true;
    }
    
    private:
    typedef vector<vector<int>> graph;
    graph createGraph(int numCourses, vector<pair<int,int>> &prerequisites) {
        graph g(numCourses);
        for(auto edge : prerequisites) {
            g[edge.second].push_back(edge.first);
        }
        return g;
    }
    
    bool aCyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if(todo[node])
            return false;
        if(done[node])
            return true;
        todo[node] = done[node] = true;
        for(auto v : g[node]) {
            if(!aCyclic(g, todo, done, v))
                return false;
        }
        todo[node] = false;
        return true;
    }
    /*vector<int> inDegree(graph& g) {
        vector<int> res(g.size(),0);
        for(auto adj : g) {
            for(auto v : adj) {
                res[v]++;
            }
        }
        return res;
    }*/
    
};


//BFS using indegree
//

class Solution {
public:
    //finding if there is a cycle in the graph
    // if cycle present, return false
    // else return true
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = createGraph(numCourses, prerequisites);
        vector<int> degree = inDegree(g);
        for(int i=0; i<numCourses; i++) {
            int j = 0;
            for(;j < numCourses; j++) {
                if(!degree[j])
                    break;
            }
            if(j == numCourses)
                return false;
            degree[j]--;
            for(auto v : g[j])
                degree[v]--;
        }
        return true;
    }

    private:
    typedef vector<vector<int>> graph;
    graph createGraph(int numCourses, vector<pair<int,int>> &prerequisites) {
        graph g(numCourses);
        for(auto edge : prerequisites) {
            g[edge.second].push_back(edge.first);
        }
        return g;
    }

    vector<int> inDegree(graph& g) {
        vector<int> res(g.size(),0);
        for(auto adj : g) {
            for(auto v : adj) {
                res[v]++;
            }
        }
        return res;
    }

};

