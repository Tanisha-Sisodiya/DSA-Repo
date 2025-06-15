class Solution {
public:
    bool helper(vector<vector<char>>& board, char temp, int i , int j ){
        int n = board.size();
        for(int k = 0; k<n; k++){
           if(board[i][k] == temp){
            return false;
           }
        }
        for(int l = 0; l<n; l++){
           if(board[l][j] == temp){
            return false;
           }
        }
        int boxRowStart = (i/3)*3;
        int boxColStart = (j/3)*3;
        for(int k = boxRowStart; k<boxRowStart+3; k++){
            for(int l = boxColStart; l<boxColStart+3; l++){
                if(board[k][l]== temp){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] != '.'){
                    char temp = board[i][j];
                    board[i][j] = '.';
                    if(!helper(board, temp, i, j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};