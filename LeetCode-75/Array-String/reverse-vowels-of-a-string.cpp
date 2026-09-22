class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u'|| c == 'U')
        return true;
        else
        return false;
    }
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high){
            if(isVowel(s[low]) && isVowel(s[high])){
                swap(s[low], s[high]);
                low++;
                high--;
            }
            if(!isVowel(s[low])){
                low++;
            }
            if(!isVowel(s[high])){
                high--;
            }
        }
        return s;
    }
};
