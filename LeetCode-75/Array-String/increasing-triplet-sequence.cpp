class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i : nums) { 

            if(i <= first) {
                first = i;
            }
            else if(i <= second) {
                second = i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
