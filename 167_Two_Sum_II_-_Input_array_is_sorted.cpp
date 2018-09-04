class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0;i<numbers.size();i++)
        {
            for(int j = i+1;j<numbers.size();j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
            }           
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        map<int,int> maps;
        for(int i=0;i<numbers.size();i++)
            maps[numbers[i]] = i;
        for(int i=0;i<numbers.size();i++)
            if(maps.count(target - numbers[i])>0 && maps[target - numbers[i]] != i)
            {
                res.push_back(i+1);
                res.push_back(maps[target-numbers[i]]+1);
                break;
            }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        map<int,int> maps;
        for(int i=0;i<numbers.size();i++)
        {
            if(maps.count(target - numbers[i])>0 && maps[target - numbers[i]] != i)
            {
                res.push_back(maps[target-numbers[i]]+1);
                res.push_back(i+1);
            }
            else
            {
                maps[numbers[i]] = i;
            }
        }
        return res;
    }
};