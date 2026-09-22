class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int p1 = s.size();
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(i + 1 < p1) {
                    int j = i + 1;
                    ans += s.substr(j, p1 - j);
                    ans += " ";
                }
                p1 = i;
            }
        }
        if(p1 > 0) {
            ans += s.substr(0, p1);
        }
        if(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
