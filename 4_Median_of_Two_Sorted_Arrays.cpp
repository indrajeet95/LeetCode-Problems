class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> sets;
        for(int i=0;i<nums1.size();i++)
            sets.insert(nums1[i]);
        for(int j=0;j<nums2.size();j++)
            sets.insert(nums2[j]);
        auto itr = sets.cbegin();
        advance(itr,sets.size()/2 - 1);
        auto itr2 = sets.cbegin();
        advance(itr2,sets.size()/2);
        if(sets.size()%2 == 0)
        {
            cout << *itr << " " << *itr2;
            return (double)(*itr + *itr2)/2;
        }
        else
        {
            return *itr2;
        }        
    }
};