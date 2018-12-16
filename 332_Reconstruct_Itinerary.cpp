class Solution {
public:
    map<string, multiset<string>> airports;
    vector<string> route;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto it=tickets.begin(); it!=tickets.end(); it++)
            airports[it->first].insert(it->second);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
    void visit(string s)
    {
        while(airports[s].size())
        {
            string next = *airports[s].begin();
            airports[s].erase(airports[s].begin());
            visit(next);
        }
        route.push_back(s);
    }
};

/*
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}