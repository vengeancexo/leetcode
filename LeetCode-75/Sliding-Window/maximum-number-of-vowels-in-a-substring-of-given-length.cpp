class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char, int> freq;
        int ans=0, left=0, right;
        for(right = 0; right < k; right++)
            freq[s[right]]++;
        ans = freq['a'] + freq['e'] + freq['i'] + freq['o'] + freq['u'];
        while(right < s.size()){
            freq[s[left]]--;
            left++;
            freq[s[right]]++;
            right++;
            ans = max(ans, freq['a'] + freq['e'] + freq['i'] + freq['o'] + freq['u']);
        }
        return ans;
    }
};
