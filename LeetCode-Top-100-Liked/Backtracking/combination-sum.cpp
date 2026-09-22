class Solution {
public:
    void helpergng(vector<vector<int>> &ans, vector<int> temp, int target, int index, int sum, vector<int> &candidates){
        if(sum == target){
            ans.push_back(temp);
            sum = 0;
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(sum + candidates[i] > target)
            continue;


            temp.push_back(candidates[i]);
            helpergng(ans, temp, target, i, sum+candidates[i], candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0, sum = 0;
        helpergng(ans, temp, target, index, sum, candidates);
        return ans;
    }
};
