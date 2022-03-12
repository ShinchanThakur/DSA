//RAT IN A MAZE
//Return paths in lexicographically increasing order

bool inBounds(int row, int col, int n){
    return (row < n and row >= 0 and col < n and col >= 0);
}

void findAllPaths(vector<vector<int>> &maze, int n, vector<string> &allPaths, string path, int row, int col, int dr[], int dc[], string dir, vector<vector<int>> &visited){
    if(row == n-1 and col == n-1){
        allPaths.push_back(path);
        return;
    }
    for(int i=0; i<4; i++){
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        if(inBounds(nextRow, nextCol, n) and maze[nextRow][nextCol] and !visited[nextRow][nextCol]){
            visited[row][col] = 1;
            findAllPaths(maze, n, allPaths, path + dir[i], nextRow, nextCol, dr, dc, dir, visited);
            visited[row][col] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n) {
    vector<string> allPaths;
    string path = "";
    int row = 0, col = 0;
    int dr[] = {1,  0, 0, -1};
    int dc[] = {0, -1, 1,  0};
    string dir = "DLRU";    //taking this in lexicographical order
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if(maze[0][0])      findAllPaths(maze, n, allPaths, path, row, col, dr, dc, dir, visited);
    return allPaths;
}

//Time complexity: O(4^(n*n))
//Space complexity: O(n*n)      -> for visited array

//Problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#