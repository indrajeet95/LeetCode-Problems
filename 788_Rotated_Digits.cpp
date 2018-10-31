class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        unordered_map<int,int> maps = {{0,0},{1,1},{2,5},{5,2},{6,9},{8,8},{9,6}};
        for(int i=1; i<=N; i++)
        {
            int ans = i;
            string digits;
            int flag = 0;
            while(ans>0)
            {
                if(maps.find(ans%10) != maps.end())
                {
                    cout << maps[ans%10] << endl;
                    digits.append(to_string(maps[ans%10]));
                }
                else
                {
                    flag = 1;
                    break;
                }
                ans = ans/10;
            }
            if(flag == 0)
            {
                reverse(digits.begin(),digits.end());
                cout << digits << endl;
                int temp = stoi(digits);
                cout << temp << endl;
                if(temp != i)
                    res++;
            }
        }
        return res;
    }
};