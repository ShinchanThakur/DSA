//SUDOKU SOLVER
//Solve the given sudoku problem

bool isValid(vector<vector<char>> &board, int row, int col, int n, char c){
    for(int i=0; i<n; i++){
        if(board[i][col] == c)      return false;
        if(board[row][i] == c)      return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)    return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board, int n){
    for(int row=0; row < n; row++){
        for(int col=0; col < n; col++){
            if(board[row][col] == '.'){
                for(char c = '1'; c <= '9'; c++){
                    if(isValid(board, row, col, n, c)){
                        board[row][col] = c;
                        if(solve(board, n))     return true;
                        else                    board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    int n = 9;
    solve(board, n);
}

//Time complexity: O(9^(n*n))       -> we can fill n*n positions in 9 ways
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/sudoku-solver/