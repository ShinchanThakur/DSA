//ROTTEN ORANGES

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), totalOranges = 0, rottenOranges = 0, daysToRot = 0;
    queue<pair<int, int>> rotten;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            if(grid[i][j])  totalOranges++;
            if(grid[i][j] == 2)
                rotten.push({i, j});
        }
    int dx[] = {0, 0 , -1, 1};
    int dy[] = {1, -1, 0 , 0};
    while(rotten.size()){
        int todayRotten = rotten.size();
        rottenOranges += todayRotten;
        while(todayRotten--){
            int ii = rotten.front().first, jj = rotten.front().second;
            rotten.pop();
            for(int k=0; k<4; k++){
                int i = ii + dx[k], j = jj + dy[k];
                if(0 <= i and i < m and 0 <= j and j < n and grid[i][j] == 1){
                    grid[i][j] = 2;
                    rotten.push({i, j});
                }
            }
        }
        if(rotten.size())
            daysToRot++;
    }
    if(totalOranges == rottenOranges)
        return daysToRot;
    else
        return -1;
}

//Time complexity: O(4 * n^2)
//Space complexity: O(n^2)      ->when all are rotten at the start

//Problem link: https://leetcode.com/problems/rotting-oranges/