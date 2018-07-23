class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++)
            if(istrue(i) == true)
                res.push_back(i);
        return res;
    }
    bool istrue(int n)
    {
        int temp = n;
        vector<int> digits;
        while(temp>0)
        {
            digits.push_back(temp%10);
            temp=temp/10;
        }
        for(int i = 0;i<digits.size();i++)
        {
            if(digits[i] == 0)
                return false;
            if(n%digits[i] != 0)
                return false;
        }
        return true;
    }
};