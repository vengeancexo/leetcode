class Solution {
public:
    bool issafe(vector<string> &board, int row, int coln, int n){
        for(int j=0;j<row;j++){
            if(board[j][coln] == 'Q'){
                return false;
            }
        }
        for(int i=row-1,j=coln-1; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q')
            return false;
        }
         for(int i=row-1,j=coln+1; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q')
            return false;
        }
        return true;
    }
    void check(vector<string> &board, int n, int row, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(board, row, i, n)){
                board[row][i] = 'Q';
                check(board, n, row+1, ans);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        check(board, n, 0, ans);
        return ans;
    }
};
