class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int pointer = 1;
        for(int i=0;i<nums.size();i++){
            ans.push_back(pointer);
            pointer *= nums[i];
        }
        pointer = 1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] = ans[i]*pointer;
            pointer *= nums[i];
        }
        return ans;
    }
};
