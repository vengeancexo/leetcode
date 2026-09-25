class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector<int>, int> freq;
        for(auto row : grid){
            freq[row]++;
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            if(freq.count(temp)){
                ans+=freq[temp];
            }
        } 
        return ans;
    }
};
