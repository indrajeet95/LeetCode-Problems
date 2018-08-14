class Solution {
public:
    int binaryGap(int N) {
        vector<int> temp;
        bitset<32> bset(N);
        for(int i=0;i<bset.size();i++)
        {
            if(bset[i] == 1)
            {
                cout << i;
                temp.push_back(i);
            }
        }
        int res = 0;
        for(int i=1;i<temp.size();i++)
            if(temp[i]-temp[i-1] > res)
                res = temp[i] -temp[i-1];
        return res;
    }
};