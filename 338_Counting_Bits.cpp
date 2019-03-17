class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0; i<=num;i++) {
            cout << "here";
            res.push_back(countOnes(i));
        }
        return res;
    }
    int countOnes(int n) {
        int res = 0;
        while(n) {
            n = n&(n-1);
            res++;
        }
        return res;
    }
};


/*
0 -    0
1 -    1 
2 -   10
3 -   11
4 -   100
5 -   101
6 -   110
7  -  111
8  - 1000
9  - 1001
10 - 1010
11 - 1011
12 - 1100
13 - 1101
14 - 1110
15 - 1111

*/

//0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4
