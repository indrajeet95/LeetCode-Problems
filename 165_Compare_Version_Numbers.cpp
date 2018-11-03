class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(auto &ch : version1) if(ch == '.') ch = ' ';
        for(auto &ch : version2) if(ch == '.') ch = ' ';
        istringstream ver1(version1);
        istringstream ver2(version2);
        int n1 = 0;
        int n2 = 0;
        while(1)
        {
            if(!(ver1 >> n1)) n1 = 0;
            if(!(ver2 >> n2)) n2 = 0;
            if(!ver1  && !ver2) 
            {
                cout << ver1 << endl;
                cout << ver2 << endl; 
                return 0;   
            }
            if(n1 > n2) return 1;
            if(n1 < n2) return -1;
        }
    }
};