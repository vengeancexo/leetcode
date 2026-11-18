class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int firstprev = max(nums[0],nums[1]), secondprev=nums[0], curr;
        for(int i=2;i<nums.size();i++){
            curr = max(secondprev + nums[i], firstprev);
            secondprev = firstprev;
            firstprev = curr;
        }
        return firstprev;
    }
};
