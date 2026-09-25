class Solution {
public:
    int compress(vector<char>& chars) {
        int p1 = 0, p2= 0;
        while(p1 < chars.size()){
            int p3 = p1;
            while(p3 < chars.size() && chars[p3] == chars[p1]){
                p3++;
            }
            int count = p3-p1;
            chars[p2] = chars[p1];
            p2++;
            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[p2] = c;
                    p2++;
                }
            }
            p1 = p3;
        }
        return p2;
    }
};
