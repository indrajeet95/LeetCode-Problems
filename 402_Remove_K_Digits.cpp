class Solution {
public:
    string removeKdigits(string num, int k) {
        // 1432219 - > 432219, 132219, 142219, 143219, 143219, 143229, 143221
        // 132219 -
        //time complexity : O(k*num.size());
        string ans = "0";
        if(num.size() == 0)
            return NULL;
        cout << num.size();
        if(num.size() == k)
            return ans;
        for(int i=0; i<k; i++)
        {
            long int temp = stoi(num.substr(1,num.size()-1));
            cout << "Integer Val: " << temp << endl;
            //string res = num;
            int index = 0;
            for(int a=1; a<num.size(); a++)
            {
                string mod = num.substr(0,a) + num.substr(a+1,num.size() - (a+1));
                cout << "If " << a << " deleted it will look like: " << mod << endl;
                if(temp > stoi(mod))
                {
                    temp = stoi(mod);
                    index = a;
                    cout << "Index to be deleted: " << index << endl;
                }
            }
            num.erase(index,1);
            cout << "After erase: " << num << endl;
        }
        while(*num.begin() == '0')
            num.erase(0,1);
        return num;
    }
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == 0)
            return NULL;
        if(k == num.size())
            return "0";
        for(int i=0; i<k; i++)
        {
            int j=0;
            while(num[j+1] >= num[j])
                j++;
            num.erase(j,1);
        }
        while(*num.begin() == '0')
            num.erase(0,1);
        return num=="" ? "0" : num;
        
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size())
            return "0";
        string res = "";
        int keep = num.size() - k;
        for(int i=0; i<num.size(); i++)
        {
            while(k>0 && res.back()>num[i])
            {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        
        while(*res.begin() == '0')
            res.erase(0,1);
        return res == "" ? "0" : res;
        
        
    }
};
