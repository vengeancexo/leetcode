class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int steps = 0;
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        vis[entrance[0]][entrance[1]] = true;
        q.push({entrance[0], entrance[1]});
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size;i++){
                int row = q.front().first;
                int coln = q.front().second;
                q.pop();

                if ((row == 0 || coln == 0 || row == maze.size()-1 || coln == maze[0].size()-1) && (row != entrance[0] || coln != entrance[1])){
                    return steps;
                }

                if(row-1 >= 0 && maze[row-1][coln] == '.' && vis[row-1][coln] == false){
                    q.push({row-1, coln});
                    vis[row-1][coln] = true;
                }

                if(row+1<maze.size() && maze[row+1][coln] == '.' && vis[row+1][coln] == false){
                    q.push({row+1, coln});
                    vis[row+1][coln] = true;
                }

                if(coln-1 >= 0 && maze[row][coln-1] == '.' && vis[row][coln-1] == false){
                    q.push({row, coln-1});
                    vis[row][coln-1] = true;
                }

                if(coln+1<maze[0].size() && maze[row][coln+1] == '.' && vis[row][coln+1] == false){
                    q.push({row, coln+1});
                    vis[row][coln+1] = true;
                }
            }
            steps++;
        }
        return -1;
    }
};
