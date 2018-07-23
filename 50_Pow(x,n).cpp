class Solution {
public:
    double myPow(double x, int n) {
       int sign = 1;
        if(n<0)
            sign = -1;
        if(n==1)
            return x;
        if(n>=0)
        {
        if(n%2 == 0)
            return pow(x*x,n/2);
        else
            return x*pow(x*x,(n/2));            
        }
        else
        {
        x = 1/x;
        if(n%2 == 0)
            return pow(x*x,-(n/2));
        else
            return x*pow(x*x,-(n/2));
        }
    }
};