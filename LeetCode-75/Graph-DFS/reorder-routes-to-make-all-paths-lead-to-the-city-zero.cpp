class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj, int u, vector<bool> &vis, int &ans){
        vis[u] = true;
        for(pair<int,int> pp : adj[u]){
            int v = pp.first;
            int cost = pp.second;
            if(!vis[v]){
                if(cost == 1){
                    ans++;
                }
                dfs(adj, v, vis, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        int ans = 0;
        vector<bool> vis(n, false);
        dfs(adj, 0, vis, ans);
        return ans;
    }
};
