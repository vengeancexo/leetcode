class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        for(int i : nums){
            totalsum += i;
        }
        int left = 0;
        for(int i=0;i<nums.size();i++){
            int right = totalsum-left-nums[i];
            if(right == left){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
