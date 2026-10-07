class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &vis){
        vis[i] = true;
        for(int j = 0; j<vis.size();j++){
            if(isConnected[i][j] == 1 && !vis[j]){
                dfs(isConnected, j, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected[0].size(), false);
        int ans = 0;
        for(int i=0; i<isConnected[0].size();i++){
           if(!vis[i]){
            ans++;
            dfs(isConnected, i, vis);
           }
        }
        return ans;
    }
};
