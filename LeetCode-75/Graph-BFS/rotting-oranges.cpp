class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        int freshoranges = 0, ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    freshoranges++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty() && freshoranges >0){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                //upper orange chekin

                if(row-1 >= 0 && grid[row-1][col] == 1){
                    grid[row-1][col] = 2;
                    freshoranges--;
                    q.push({row-1, col});
                }

                //lower orange checkin

                if(row+1 < m && grid[row+1][col] == 1){
                    grid[row+1][col] = 2;
                    freshoranges--;
                    q.push({row+1, col});
                }

                //zara sa left

                if(col-1 >=0 && grid[row][col-1] == 1){
                    grid[row][col-1] = 2;
                    freshoranges--;
                    q.push({row, col-1});
                }

                //zara sa right

                if(col+1 < n && grid[row][col+1] == 1){
                    grid[row][col+1] = 2;
                    freshoranges--;
                    q.push({row, col+1});
                }
            }
            ans++;
        }
        if(freshoranges == 0){
            return ans;
        }
        return -1;
    }
};
