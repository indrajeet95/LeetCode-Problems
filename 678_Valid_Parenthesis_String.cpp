//creating a range is the hint
//two variables that keep track of counts of ( and )
//at any point in time if count of ) greater than (, then return false happens when high <0
//finally if there a possibility low is zero at the end of string, then it is valid
//we check if low is > 0 and then only decrement it. if it is already zero we do not because we are considering the possiblity
//that it can be a NULL character

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                low++;
                high++;
            }
            else if(s[i] == ')')
            {
                if(low>0)
                    low--;
                high--;
            }
            else
            {
                if(low>0)
                    low--;
                high++;
            }
            if(high<0)
                return false;
        }
        if(low == 0)
            return true;
        else
            return false;
    }
};