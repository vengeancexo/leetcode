class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<bool> &vis, int room){
        if(vis[room]){
            return;
        }
        vis[room] = true;
        for(int i = 0; i<rooms[room].size();i++){
            dfs(rooms, vis, rooms[room][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, vis, 0);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
