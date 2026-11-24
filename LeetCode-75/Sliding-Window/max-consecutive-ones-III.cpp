class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0, maxisum = 0, left = 0;
        for(int right=0;right<nums.size();right++){
            if(nums[right] == 0)
            zeroes++;
            while(zeroes > k){
                if(nums[left] == 0)
                zeroes--;
                left++;
            }
            maxisum = max(maxisum, right-left+1);
        }
        return maxisum;
    }
};
