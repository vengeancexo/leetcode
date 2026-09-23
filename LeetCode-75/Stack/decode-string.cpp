class Solution {
public:
    string decodeString(string s) {
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        string str = "";
        for(char c : s){
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else if(c == '['){
                nums.push(num);
                strs.push(str);
                num = 0;
                str = "";
            }
            else if(c == ']'){
                int prevnum = nums.top();
                nums.pop();
                string prevstr = strs.top();
                strs.pop();
                string temp = "";
                for(int i=0;i<prevnum;i++){
                    temp += str;
                }
                str = prevstr+temp;
            }
            else{
                str += c;
            }
        }
        return str;
    }
};
