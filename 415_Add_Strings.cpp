class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1c = num1.size()-1;
        int num2c = num2.size()-1;
        int sum = 0;
        string res = "";
        while(num1c>=0 || num2c >=0 || sum>0)
        {
            if(num1c>=0)
            {
                sum += num1[num1c] - '0';
                num1c--;            
            }
            if(num2c >= 0)
            {
            sum += num2[num2c] - '0';
            num2c--;                
            }
            
            //res.append(1, sum%10 + '0');
            //cout << res << endl;
            res.insert(0,1,(sum%10 + '0'));
            sum /= 10;
        }
        return res;
        
    }
};
/*
string addStrings(string num1, string num2) {
    int sum = 0, i = num1.length() - 1, j = num2.length() - 1;
    string str;
    while (i >= 0 || j >= 0 || sum > 0) {
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        str.insert(0, 1, (sum % 10) + '0');
        sum /= 10;
    }
    return str;
}