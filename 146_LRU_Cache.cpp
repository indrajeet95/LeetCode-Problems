class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> holder;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            holder.splice(holder.begin(),holder,cache[key]);
            return cache[key]->second;
        }
        else
            return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end())
        {
            if(cache.size() == capacity)
            {
                cache.erase(holder.back().first);
                holder.pop_back();
            }
            holder.push_front(make_pair(key,value));
            cache[key] = holder.begin();
        }
        else
        {
            cache[key]->second = value;
            holder.splice(holder.begin(),holder,cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */