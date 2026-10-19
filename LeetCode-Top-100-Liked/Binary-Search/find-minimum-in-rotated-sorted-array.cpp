class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1]){
            return nums[0];
        }
        int p1=0, p2= nums.size()-1, mid;
        while(p1 < p2){
            mid = (p1+p2)/2;
            if(nums[mid] > nums[p2]){
                p1 = mid+1;
            }
            if(nums[mid] <= nums[p2]){
                p2 = mid;
            }
        }
        return nums[p1];
    }
};
