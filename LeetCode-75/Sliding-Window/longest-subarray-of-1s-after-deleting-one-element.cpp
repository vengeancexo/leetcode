class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int p1=0, ans=0, zerocount=0, tempcount=0;
        for(int p2=0;p2<nums.size();p2++){
            if(nums[p2] == 0){
                zerocount++;
            }
            while(zerocount>1){
                if(nums[p1]==0){
                    zerocount--;
                }
                p1++;
            }
            ans = max(ans, p2 - p1);
        }
        return ans;
    }
};
