class Solution {
public:
    void helper(vector<string> &ans, string temp, string digits, vector<string> &phone, int index){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[index] - '0';
        for(int i = 0; i < phone[digit].size(); i++) {
            temp.push_back(phone[digit][i]);
            helper(ans, temp, digits, phone, index+1);
            temp.pop_back();
        }
}

    vector<string> letterCombinations(string digits) {
        vector<string> phone = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
    };
    vector<string> ans;
    string temp;
    int index = 0;
    helper(ans, temp, digits, phone, index);
    return ans;
}};
