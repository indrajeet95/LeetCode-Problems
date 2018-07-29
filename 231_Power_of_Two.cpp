//just cause i know what a bitset is :p
//however this occupies a teeny space thingy

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> bits(n);
        if(n<0)
            return false;
        if(bits.count() == 1)
            return true;
        else
            return false;
    }
};

//thebetter method 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return !(n&n-1);
        
    }
};