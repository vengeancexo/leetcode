class Solution {
public:
    void helper(vector<string> &ans, int n, int open, int close, string temp){
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            helper(ans, n, open+1, close, temp);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            helper(ans, n, open, close+1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int open = 0, close = 0;
        helper(ans, n, open, close, temp);
        return ans;
    }
};
