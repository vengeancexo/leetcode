class Solution {
public:
    void helper(int start, int k, int n, int sum, vector<vector<int>> &ans, vector<int> &temp){
        if(temp.size() == k){
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }
        for(int i = start; i<=9;i++){   
            sum += i;
            temp.push_back(i);
            helper(i+1, k, n, sum, ans, temp);
            temp.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1, k, n, 0, ans, temp);
        return ans;
    }
};
