//addicted to bitset and hence using it even if its unnecessary

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        bitset<32> bits(num);
        if(bits.count() == 1)
        {
            int index = 0;
            for(int i=0;i<32;i++)
            {
                if(bits[i] == 1)
                {
                    index = i;
                    break;
                }
            }
            if(index%2 == 0)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

//0x55555555: 1010101010101...
//only has 1 in odd places
//power of 4 can be differentiated by the fact that 1 will be in odd place.


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && !(num&num-1) && num&0x55555555;
        
    }
};