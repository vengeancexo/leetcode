class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for(char c : word1){
            freq1[c]++;
        }
        for(char c : word2){
            freq2[c]++;
        }
        if(freq1.size() != freq2.size()){
            return false;
        }
        for(auto [c,freq] : freq1){
            if(!freq2.count(c)){
                return false;
            }
        }
        vector<int> f1;
        vector<int> f2;
        for(auto [c,freq] : freq1){
            f1.push_back(freq);
        }
        for(auto [c,freq] : freq2){
            f2.push_back(freq);
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2;
    }
};
