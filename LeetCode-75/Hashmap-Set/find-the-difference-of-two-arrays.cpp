class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1set;
        unordered_set<int> nums2set;
        for(int i:nums1){
            nums1set.insert(i);
        }
        for(int i: nums2){
            nums2set.insert(i);
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i : nums1set){
            if(!nums2set.count(i)){
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
        temp.clear();
        for(int i : nums2set){
            if(!nums1set.count(i)){
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
