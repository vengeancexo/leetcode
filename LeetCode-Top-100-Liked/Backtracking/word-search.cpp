class Solution {
public:
    bool dfs(int i, int j, int index, vector<vector<bool>> &visited, string word, vector<vector<char>> &board){
        if(index == word.size()-1)
            return true;
        visited[i][j] = true;

        if (i - 1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[index+1]) {
            if (dfs(i-1, j, index+1, visited, word, board))
                return true;
        }
        if(i+1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[index+1]){
            if(dfs(i+1,j,index+1, visited, word, board))
                return true;
        }
        if(j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[index+1]){
            if(dfs(i,j-1,index+1, visited, word, board))
                return true;
        }
        if(j+1 < board[0].size() && !visited[i][j+1] && board[i][j+1] == word[index+1]){
            if(dfs(i,j+1,index+1, visited, word, board))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,visited,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
