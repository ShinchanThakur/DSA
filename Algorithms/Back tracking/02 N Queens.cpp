//N QUEENS PROBLEM
//Place n queens such that they cant attack each other

bool isSafe(int n, vector<string> &board, int row, int col){
    //All checking needs to be done on left side only
    //Since we are filling the board from left to right

    int dupRow = row, dupCol = col;
    //checking upper diagonal
    while(row >= 0 and col >= 0)
        if(board[row--][col--] == 'Q')    return false;

    //checking lower diagonal
    row = dupRow, col = dupCol;
    while(row < n and col >=0)
        if(board[row++][col--] == 'Q')    return false;

    //checking row
    row = dupRow, col = dupCol;
    while(col >= 0)
        if(board[row][col--] == 'Q')    return false;

    return true;
}

void getPossibleArrangements(int n, vector<string> &board, vector<vector<string>> &nQueensSolution, int col){
    if(col == n){
        nQueensSolution.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(n, board, row, col)){
            board[row][col] = 'Q';
            getPossibleArrangements(n, board, nQueensSolution, col + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>  nQueensSolution;
    vector<string> board(n);
    string emptyRow(n, '.');
    for(int i=0; i<n; i++)
        board[i] = emptyRow;
    int col = 0;
    getPossibleArrangements(n, board, nQueensSolution, col);
    return nQueensSolution;
}

//Time complexity: O(2^(n*n) *n)        All n*n places can take 2 positions-> either . or Q
//                                        The isSafe() takes O(n) too
//Space complexity: O(n*n *x)           x-> number of solutions

//Problem link: https://leetcode.com/problems/n-queens/

/***********************************************************************************************************/

//OPTIMISING THE IS SAFE FUNCTION ->To take O(1) time only
// upper diagonal -> row+col
// lower diagonal -> (n-row-1) + col;

bool isSafe(int n, int row, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
    if(leftRow[row])    return false;
    if(upperDiagonal[row + col])    return false;
    if(lowerDiagonal[n-row-1 + col])    return false;
    return true;
}

void getPossibleArrangements(int n, vector<string> &board, vector<vector<string>> &nQueensSolution, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
    if(col == n){
        nQueensSolution.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(n, row, col, leftRow, upperDiagonal, lowerDiagonal)){
            board[row][col] = 'Q';
            leftRow[row] = upperDiagonal[row + col] = lowerDiagonal[n-row-1 + col] = 1;
            getPossibleArrangements(n, board, nQueensSolution, col+1, leftRow, upperDiagonal, lowerDiagonal);
            leftRow[row] = upperDiagonal[row + col] = lowerDiagonal[n-row-1 + col] = 0;
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> nQueensSolution;
    vector<string> board(n);
    string emptyRow(n, '.');
    for(int i=0; i<n; i++)
        board[i] = emptyRow;
    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2*n - 1);
    vector<int> lowerDiagonal(2*n - 1);
    int col = 0;
    getPossibleArrangements(n, board, nQueensSolution, col, leftRow, upperDiagonal, lowerDiagonal);
    return nQueensSolution;
}