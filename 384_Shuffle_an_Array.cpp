class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        for(int i=0; i< res.size(); i++)
        {
            swap(res[i], res[rand()%res.size()]);
        }
        return res;
        
    }
};
