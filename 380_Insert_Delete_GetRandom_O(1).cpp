class RandomizedSet {
private:
    unordered_map<int,int> map;
    vector<int> holder;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end())
            return false;
        else
        {
            holder.push_back(val);
            map[val] = holder.size()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false;
        else
        {
            int end = holder.back();
            map[end] = map[val];
            holder[map[val]] = end;
            map.erase(val);
            holder.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return holder[rand()%holder.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

class RandomizedSet {
private:
    unordered_map<int,int> map;
    vector<int> holder;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end())
            return false;
        else
        {
            holder.push_back(val);
            map[val] = holder.size()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false;
        else
        {
            cout << "Going to remove element " << val << endl;
            cout << "map:" << endl;
            for(auto it = map.begin(); it != map.end(); it++)
                cout << it->first << " " << it->second << endl;
            cout << "holder: " << endl;
            for(auto val : holder)
                cout << val << " ";
            cout << endl;
            int end = holder.back(); //returns the actual element at the end of the holder
            cout << end << endl;
            map[end] = map[val]; //update index of end element with index of to be deleted element
            holder[map[val]] = end; //update the value of holder with end element 
            map.erase(val); //erase the entry of val in map
            holder.pop_back(); // pop back the last element in holder
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return holder[rand()%holder.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */