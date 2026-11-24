class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0, high = 0;
        while(high < nums.size()){
            if(nums[high] != 0){
                nums[low] = nums[high];
                low++;
            }
            high++;
        }
            while(low<nums.size()){
                nums[low] = 0;
                low++;
            }
        }
};
