class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        else if(A == B && set<char>(A.begin(),A.end()).size() < A.size())
            return true;
        else
        {
            cout << "yo";
            vector<int> diff;
            for(int k=0; k<A.size(); k++)
                if(A[k] != B[k])
                    diff.push_back(k);
            return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
        }
    }
};