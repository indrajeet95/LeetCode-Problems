//first problem attempted using bitset
//count function returns the total number of set bits in the bitset which is checked if it equals to nums
//bitset size is 10 since we have a total 10 bits to represent both hour and mins
//we shift by 6 bits to make space for mins

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h=0;h<12;h++)
        {
            for(int m = 0;m<60;m++)
            {
                if(bitset<10>(h<<6|m).count() == num)
                    res.push_back(to_string(h) + (m<10?":0":":")+to_string(m));
            }
        }
        return res;
    }
};