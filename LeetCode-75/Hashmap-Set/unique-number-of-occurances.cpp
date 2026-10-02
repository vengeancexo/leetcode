class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        unordered_set<int> exists;
        for(pair<int,int> element : freq){
            if(exists.count(element.second))
                return false;
            exists.insert(element.second);
        }
        return true;
    }
};
